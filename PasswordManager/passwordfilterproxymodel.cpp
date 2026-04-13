#include "passwordfilterproxymodel.h"

PasswordFilterProxyModel::PasswordFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

void PasswordFilterProxyModel::setCategoryFilter(const QString &category)
{
    beginFilterChange();
    if (category == "All") {
        m_category = "";
    } else {
        m_category = category;
    }
    endFilterChange();
}

void PasswordFilterProxyModel::setTextFilter(const QString &text)
{
    beginFilterChange();
    m_text = text;
    endFilterChange();
}

bool PasswordFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex titleIndex = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex categoryIndex = sourceModel()->index(sourceRow, 5, sourceParent);

    QString title = sourceModel()->data(titleIndex).toString();
    QString category = sourceModel()->data(categoryIndex).toString();

    bool textOk = m_text.isEmpty() || title.contains(m_text, Qt::CaseInsensitive);
    bool categoryOk = m_category.isEmpty() || category == m_category;

    return textOk && categoryOk;
}
