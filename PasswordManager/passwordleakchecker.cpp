#include "passwordleakchecker.h"
#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>

PasswordLeakChecker::PasswordLeakChecker(QObject *parent)
    : QObject(parent), m_networkManager(new QNetworkAccessManager(this))
{
}

void PasswordLeakChecker::checkPassword(const QString &password)
{
    if (password.isEmpty()) {
        emit checkFailed("Пароль порожній.");
        return;
    }

    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1).toHex().toUpper();
    QString prefix = hash.left(5);
    m_currentSuffix = hash.mid(5);
    QUrl url("https://api.pwnedpasswords.com/range/" + prefix);
    QNetworkRequest request(url);

    request.setRawHeader("Add-Padding", "true");
    request.setTransferTimeout(10000);

    QNetworkReply *reply = m_networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            emit checkFailed("Помилка мережі: " + reply->errorString());
            reply->deleteLater();
            return;
        }
        QByteArray responseData = reply->readAll();
        QList<QByteArray> lines = responseData.split('\n');
        bool found = false;
        int leakCount = 0;
        for (const QByteArray &line : lines) {
            QByteArray cleanLine = line.trimmed();
            if (cleanLine.isEmpty()) continue;
            QList<QByteArray> parts = cleanLine.split(':');
            if (parts.size() == 2) {
                if (parts[0] == m_currentSuffix.toUtf8()) {
                    found = true;
                    leakCount = parts[1].toInt();
                    break;
                }
            }
        }
        emit checkCompleted(found, leakCount);
        reply->deleteLater();
    });
}

BatchCheckResult PasswordLeakChecker::runBatchCheck(const QList<QString> &passwords, QObject *receiver)
{
    BatchCheckResult result;
    result.total = passwords.size();
    QNetworkAccessManager manager;
    for (int i = 0; i < passwords.size(); ++i) {
        QString password = passwords[i];
        if (!password.isEmpty()) {
            QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1).toHex().toUpper();
            QString prefix = hash.left(5);
            QString suffix = hash.mid(5);
            QNetworkRequest request(QUrl("https://api.pwnedpasswords.com/range/" + prefix));
            request.setRawHeader("Add-Padding", "true");
            QNetworkReply *reply = manager.get(request);
            QEventLoop loop;
            QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
            loop.exec();
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray response = reply->readAll();
                if (response.contains(suffix.toUtf8())) {
                    result.compromised++;
                }
            }
            reply->deleteLater();
        }
        result.checked++;
        if (receiver) {
            QMetaObject::invokeMethod(receiver, "updateBatchProgress", Qt::QueuedConnection, Q_ARG(int, result.checked), Q_ARG(int, result.total));
        }
    }
    return result;
}
