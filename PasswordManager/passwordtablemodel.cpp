#include "passwordtablemodel.h"
#include <QDateTime>

PasswordTableModel::PasswordTableModel(Repository *repository, QObject *parent)
    : QAbstractTableModel(parent), m_repository(repository)
{
}

int PasswordTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return m_items.size();
}

int PasswordTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return 7;
}

QVariant PasswordTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QVariant();

    switch (section) {
    case 0: return "ID";
    case 1: return "Title";
    case 2: return "Username";
    case 3: return "Password";
    case 4: return "Website";
    case 5: return "Category";
    case 6: return "Updated At";
    default: return QVariant();
    }
}

QVariant PasswordTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const PasswordRecord &item = m_items.at(index.row());

        switch (index.column()) {
        case 0: return item.id;
        case 1: return item.title;
        case 2: return item.username;
        case 3: return item.password;
        case 4: return item.website;
        case 5: return item.category;
        case 6: return item.updatedAt;
        default: return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags PasswordTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return Qt::NoItemFlags;
    if (index.column() == 0 || index.column() == 6) {
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    }

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool PasswordTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    PasswordRecord updatedItem = m_items[index.row()];

    switch (index.column()) {
    case 1: updatedItem.title = value.toString(); break;
    case 2: updatedItem.username = value.toString(); break;
    case 3: updatedItem.password = value.toString(); break;
    case 4: updatedItem.website = value.toString(); break;
    case 5: updatedItem.category = value.toString(); break;
    default: return false;
    }

    updatedItem.updatedAt = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    if (m_repository && m_repository->update(updatedItem)) {
        m_items[index.row()] = updatedItem;

        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        QModelIndex dateIndex = this->index(index.row(), 6);
        emit dataChanged(dateIndex, dateIndex, {Qt::DisplayRole});

        return true;
    }

    return false;
}

void PasswordTableModel::setItems(const QList<PasswordRecord> &items)
{
    beginResetModel();
    m_items = items;
    endResetModel();
}

PasswordRecord PasswordTableModel::itemAt(int row) const
{
    if (row >= 0 && row < m_items.size())
        return m_items.at(row);
    return PasswordRecord();
}
