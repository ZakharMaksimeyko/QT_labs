#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDateTime>

struct Ticket {
    int id;
    QString title;
    QString status;
    QString priority;
    QString description;
    QDateTime createdAt;
};

#endif // TICKET_H
