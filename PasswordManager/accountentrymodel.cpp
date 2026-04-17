#include "accountentrymodel.h"

AccountEntryModel::AccountEntryModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    m_accounts.append({1, "Google account", "Ivan", "12345678", "google.com", "Important", QDateTime::currentDateTime().addDays(-1)});
}

int AccountEntryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return m_accounts.size();
}

int AccountEntryModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return ColCount;
}

QVariant AccountEntryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_accounts.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const Account &account = m_accounts.at(index.row());

        switch (index.column()) {
        case IdCol:         return account.id;
        case TitleCol:      return account.title;
        case UsernameCol:   return account.password;
        case PasswordCol:   return account.password;
        case WebsiteCol:    return account.website;
        case CategoryCol:   return account.category;
        case CreatedAtCol:  return account.createdAt.toString("yyyy-MM-dd HH:mm");
        default:            return QVariant();
        }
    }
    return QVariant();
}

QVariant AccountEntryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case IdCol:         return "ID";
        case TitleCol:      return "Title";
        case UsernameCol:   return "Username";
        case PasswordCol:   return "Username";
        case WebsiteCol:    return "Website";
        case CategoryCol:   return "Category";
        case CreatedAtCol:  return "Created At";
        default:            return QVariant();
        }
    }
    return QVariant();
}


void AccountEntryModel::addAccount(const Account &account)
{
    int newRow = m_accounts.size();
    beginInsertRows(QModelIndex(), newRow, newRow);
    m_accounts.append(account);
    endInsertRows();
}

void AccountEntryModel::updateAccount(int row, const Account &account)
{
    if (row < 0 || row >= m_accounts.size()) return;

    m_accounts[row] = account;
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, ColCount - 1);
    emit dataChanged(topLeft, bottomRight);
}

void AccountEntryModel::removeAccount(int row)
{
    if (row < 0 || row >= m_accounts.size()) return;

    beginRemoveRows(QModelIndex(), row, row);
    m_accounts.removeAt(row);
    endRemoveRows();
}

Account AccountEntryModel::getAccount(int row) const
{
    if (row < 0 || row >= m_accounts.size()) return Account();
    return m_accounts.at(row);
}
