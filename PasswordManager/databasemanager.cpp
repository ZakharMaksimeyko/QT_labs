#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::open(const QString &filePath)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(filePath);
    if (!m_db.open()) {
        qDebug() << "db unsucces:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "db succes:" << filePath;
    return true;
}

bool DatabaseManager::initializeSchema()
{
    if (!m_db.isOpen()) {
        qDebug() << "db unsucces. Imposible to initialize schema.";
        return false;
    }

    QSqlQuery query(m_db);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS vault_items (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT NOT NULL,
        username TEXT,
        password TEXT,
        website TEXT,
        category TEXT,
        updated_at TEXT
    ))";
    if (!query.exec(sql)) {
        qDebug() << "Create table error:" << query.lastError().text();
        return false;
    }
    qDebug() << "Schema succes.";
    return true;
}

QSqlDatabase DatabaseManager::database() const
{
    return m_db;
}
