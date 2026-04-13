#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlDatabase>
#include <QList>
#include "passwordrecord.h"

class Repository
{
public:
    explicit Repository(const QSqlDatabase &db);

    QList<PasswordRecord> loadAll() const;

    bool insert(const PasswordRecord &record);
    bool update(const PasswordRecord &record);
    bool remove(int id);

private:
    QSqlDatabase m_db;
};

#endif // REPOSITORY_H
