#ifndef CSVTICKETREPOSITORY_H
#define CSVTICKETREPOSITORY_H

#include <QString>
#include <QList>
#include "ticket.h"

class CsvTicketRepository
{
public:
    explicit CsvTicketRepository(const QString &filePath);

    QList<Ticket> loadAll() const;

    bool saveAll(const QList<Ticket> &items) const;

private:
    QString m_filePath;
};

#endif // CSVTICKETREPOSITORY_H
