#ifndef ACCOUNTENTRYMODEL_H
#define ACCOUNTENTRYMODEL_H

#include "accountentry.h"
#include <QAbstractTableModel>
#include <QVector>

class AccountEntryModel : public QAbstractTableModel{

    Q_OBJECT

public:
    enum Column { IdCol, TitleCol, UsernameCol, PasswordCol, WebsiteCol, CategoryCol, CreatedAtCol, ColCount};

    explicit AccountEntryModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void addAccount(const Account &account);
    void updateAccount(int row, const Account &account);
    void removeAccount(int row);

    Account getAccount(int row) const;

private:
    QVector<Account> m_accounts;
};

#endif // ACCOUNTENTRYMODEL_H
