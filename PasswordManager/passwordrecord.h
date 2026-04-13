#ifndef PASSWORDRECORD_H
#define PASSWORDRECORD_H

#include <QString>

struct PasswordRecord
{
    int id = 0;
    QString title;
    QString username;
    QString password;
    QString website;
    QString category;
    QString updatedAt;
};

#endif // PASSWORDRECORD_H
