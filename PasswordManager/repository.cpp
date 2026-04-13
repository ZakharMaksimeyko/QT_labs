#include "repository.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

Repository::Repository(const QSqlDatabase &db) : m_db(db)
{
}

QList<PasswordRecord> Repository::loadAll() const
{
    QList<PasswordRecord> items;
    QSqlQuery query(m_db);
    if (!query.exec("SELECT id, title, username, password, website, category, updated_at FROM vault_items")) {
        qDebug() << "Помилка читання даних:" << query.lastError().text();
        return items;
    }
    while (query.next()) {
        PasswordRecord item;
        item.id = query.value(0).toInt();
        item.title = query.value(1).toString();
        item.username = query.value(2).toString();
        item.password = query.value(3).toString();
        item.website = query.value(4).toString();
        item.category = query.value(5).toString();
        item.updatedAt = query.value(6).toString();

        items.append(item);
    }
    return items;
}

bool Repository::insert(const PasswordRecord &record)
{
    QSqlQuery query(m_db);

    query.prepare(
        "INSERT INTO vault_items (title, username, password, website, category, updated_at) "
        "VALUES (:title, :username, :password, :website, :category, :updatedAt)"
        );

    query.bindValue(":title", record.title);
    query.bindValue(":username", record.username);
    query.bindValue(":password", record.password);
    query.bindValue(":website", record.website);
    query.bindValue(":category", record.category);
    query.bindValue(":updatedAt", record.updatedAt);

    if (!query.exec()) {
        qDebug() << "Помилка вставки запису:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Repository::update(const PasswordRecord &record)
{
    QSqlQuery query(m_db);

    query.prepare(
        "UPDATE vault_items SET "
        "title = :title, username = :username, password = :password, "
        "website = :website, category = :category, updated_at = :updatedAt "
        "WHERE id = :id"
        );

    query.bindValue(":title", record.title);
    query.bindValue(":username", record.username);
    query.bindValue(":password", record.password);
    query.bindValue(":website", record.website);
    query.bindValue(":category", record.category);
    query.bindValue(":updatedAt", record.updatedAt);
    query.bindValue(":id", record.id);

    if (!query.exec()) {
        qDebug() << "Помилка оновлення запису:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Repository::remove(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM vault_items WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Помилка видалення запису:" << query.lastError().text();
        return false;
    }
    return true;
}
