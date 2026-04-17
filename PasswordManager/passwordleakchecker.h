#ifndef PASSWORDLEAKCHECKER_H
#define PASSWORDLEAKCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

struct BatchCheckResult {
    int total = 0;
    int checked = 0;
    int compromised = 0;
};

class PasswordLeakChecker : public QObject
{
    Q_OBJECT
public:
    explicit PasswordLeakChecker(QObject *parent = nullptr);

    void checkPassword(const QString &password);

    static BatchCheckResult runBatchCheck(const QList<QString> &passwords, QObject *receiver);

signals:
    void checkCompleted(bool isCompromised, int count);
    void checkFailed(const QString &errorMessage);

private:
    QNetworkAccessManager *m_networkManager;
    QString m_currentSuffix;
};

#endif // PASSWORDLEAKCHECKER_H
