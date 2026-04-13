#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    bool open(const QString &filePath);
    bool initializeSchema();

    QSqlDatabase database() const;

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
