#include "tickettablemodel.h"

TicketTableModel::TicketTableModel(QObject *parent) : QAbstractTableModel{parent}{}

int TicketTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return m_tickets.size();
}

int TicketTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return ColCount;
}

QVariant TicketTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_tickets.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const Ticket &ticket = m_tickets.at(index.row());

        switch (index.column()) {
        case IdCol:         return ticket.id;
        case TitleCol:      return ticket.title;
        case PriorityCol:   return ticket.priority;
        case StatusCol:     return ticket.status;
        case CreatedAtCol:  return ticket.createdAt.toString("yyyy-MM-dd HH:mm");
        default:            return QVariant();
        }
    }
    return QVariant();
}

QVariant TicketTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case IdCol:         return "ID";
        case TitleCol:      return "Title";
        case PriorityCol:   return "Priority";
        case StatusCol:     return "Status";
        case CreatedAtCol:  return "Created At";
        default:            return QVariant();
        }
    }
    return QVariant();
}


void TicketTableModel::addTicket(const Ticket &ticket)
{
    int newRow = m_tickets.size();
    beginInsertRows(QModelIndex(), newRow, newRow);
    m_tickets.append(ticket);
    endInsertRows();
}

void TicketTableModel::updateTicket(int row, const Ticket &ticket)
{
    if (row < 0 || row >= m_tickets.size()) return;

    m_tickets[row] = ticket;
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, ColCount - 1);
    emit dataChanged(topLeft, bottomRight);
}

void TicketTableModel::removeTicket(int row)
{
    if (row < 0 || row >= m_tickets.size()) return;

    beginRemoveRows(QModelIndex(), row, row);
    m_tickets.removeAt(row);
    endRemoveRows();
}

Ticket TicketTableModel::getTicket(int row) const
{
    if (row < 0 || row >= m_tickets.size()) return Ticket();
    return m_tickets.at(row);
}

void TicketTableModel::setItems(const QList<Ticket> &items)
{
    beginResetModel();
    m_tickets = items;
    endResetModel();
}

QList<Ticket> TicketTableModel::getItems() const
{
    return m_tickets;
}
