#include "csvticketrepository.h"
#include "ticket.h"
#include <QFile>
#include <QSaveFile>
#include <QTextStream>
#include <QStringList>

CsvTicketRepository::CsvTicketRepository(const QString &filePath): m_filePath(filePath){}
QList<Ticket> CsvTicketRepository::loadAll() const
{
    QList<Ticket> items;
    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return items;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    if (!in.atEnd()) {
        in.readLine();
    }
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;
        QStringList parts = line.split(',');
        if (parts.size() >= 6) {
            Ticket entry;
            entry.id = parts[0].toInt();
                entry.title = parts[1];
                entry.priority = parts[2];
            entry.status = parts[3];
                entry.description = parts[4];
            entry.createdAt = QDateTime::fromString(parts[5], Qt::ISODate);
            items.append(entry);
        }
    }
    return items;
}

bool CsvTicketRepository::saveAll(const QList<Ticket> &items) const
{
    QSaveFile file(m_filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return false;
    }
    QTextStream out(&file);
        out.setEncoding(QStringConverter::Utf8);
        out << "Id,Title,Priority,Status,Description,CreatedAt\n";
    for (const Ticket &entry : items) {
        QString safeTitle = entry.title;
        safeTitle.replace(",", " ");
        QString safeDesc = entry.description;
        safeDesc.replace(",", " ");
        safeDesc.replace("\n", " ");
        safeDesc.replace("\r", "");
        out << entry.id << "," << safeTitle << "," << entry.priority << "," << entry.status << "," << safeDesc << "," << entry.createdAt.toString(Qt::ISODate) << "\n";
    }
    return file.commit();
}
