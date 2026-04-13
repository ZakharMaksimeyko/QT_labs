#ifndef PASSWORDFILTERPROXYMODEL_H
#define PASSWORDFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class PasswordFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit PasswordFilterProxyModel(QObject *parent = nullptr);

    void setCategoryFilter(const QString &category);
    void setTextFilter(const QString &text);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_category;
    QString m_text;
};

#endif // PASSWORDFILTERPROXYMODEL_H
