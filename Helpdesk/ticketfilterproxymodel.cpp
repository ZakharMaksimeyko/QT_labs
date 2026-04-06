#include "ticketfilterproxymodel.h"

TicketFilterProxyModel::TicketFilterProxyModel(QObject *parent) : QSortFilterProxyModel(parent){}

void TicketFilterProxyModel::setStatusFilter(const QString &status)
{
    beginFilterChange();
    m_status = status;
    endFilterChange();
}

void TicketFilterProxyModel::setPriorityFilter(const QString &priority)
{
    beginFilterChange();
    m_priority = priority;
    endFilterChange();
}

void TicketFilterProxyModel::setTextFilter(const QString &text)
{
    beginFilterChange();
    m_text = text;
    endFilterChange();
}

bool TicketFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex titleIndex = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex priorityIndex = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex statusIndex = sourceModel()->index(sourceRow, 3, sourceParent);

    QString title = sourceModel()->data(titleIndex).toString();
    QString priority = sourceModel()->data(priorityIndex).toString();
    QString status = sourceModel()->data(statusIndex).toString();

    bool matchesText = m_text.isEmpty() || title.contains(m_text, Qt::CaseInsensitive);
    bool matchesStatus = m_status.isEmpty() || m_status == "All" || status == m_status;
    bool matchesPriority = m_priority.isEmpty() || m_priority == "All" || priority == m_priority;

    return matchesText && matchesStatus && matchesPriority;
}
