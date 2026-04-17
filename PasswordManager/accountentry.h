#ifndef ACCOUNTENTRY_H
#define ACCOUNTENTRY_H

#include <QString>
#include <QDateTime>

struct Account {
    int id;
    QString title;
    QString username;
    QString password;
    QString website;
    QString category;
    QDateTime createdAt;
};

#endif // ACCOUNTENTRY_H
