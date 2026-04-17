#ifndef PASSWORDLEAKCHECKER_H
#define PASSWORDLEAKCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class PasswordLeakChecker : public QObject
{
    Q_OBJECT
public:
    explicit PasswordLeakChecker(QObject *parent = nullptr);

    void checkPassword(const QString &password);

signals:
    void checkCompleted(bool isCompromised, int count);
    void checkFailed(const QString &errorMessage);

private:
    QNetworkAccessManager *m_networkManager;
    QString m_currentSuffix;
};

#endif // PASSWORDLEAKCHECKER_H
