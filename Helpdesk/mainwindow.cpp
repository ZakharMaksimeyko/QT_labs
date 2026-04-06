#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new TicketTableModel(this);
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    auto *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(TicketTableModel::TitleCol, QHeaderView::Stretch);
    header->setSectionResizeMode(TicketTableModel::IdCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::PriorityCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::StatusCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::CreatedAtCol, QHeaderView::ResizeToContents);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);
    updateActions();

    ticketDialog = new TicketDialog(this);
    connect(ticketDialog, &TicketDialog::createRequested, this, [this](const Ticket &ticket) {
        Ticket newTicket = ticket;
        int maxId = 0;
        for (int i = 0; i < m_model->rowCount(); ++i) {
            int currentId = m_model->getTicket(i).id;
            if (currentId > maxId) {
                maxId = currentId;
            }
        }
        newTicket.id = maxId + 1;
        m_model->addTicket(newTicket);
        saveData();
    });
    connect(ticketDialog, &TicketDialog::updateRequested, this, [this](const Ticket &ticket) {
        QModelIndex cur = ui->tableView->currentIndex();
        if (cur.isValid()) {
            m_model->updateTicket(cur.row(), ticket);
            saveData();
        }
    });

    m_repository = new CsvTicketRepository("tickets.csv");
    QList<Ticket> loadedTickets = m_repository->loadAll();
    m_model->setItems(loadedTickets);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateActions()
{
    bool hasSelection = ui->tableView->selectionModel()->hasSelection();
    ui->actionView->setEnabled(hasSelection);
    ui->actionEdit->setEnabled(hasSelection);
    ui->actionDelete->setEnabled(hasSelection);
}

void MainWindow::on_actionNew_triggered() {
    ticketDialog->setMode(TicketDialog::DialogMode::New);
    ticketDialog->loadTicket(Ticket{0, "", "Open", "Low", "", QDateTime::currentDateTime()});
    ticketDialog->show();
    ticketDialog->raise();
    ticketDialog->activateWindow();
}

void MainWindow::on_actionEdit_triggered() {
    QModelIndex cur = ui->tableView->currentIndex();
    if (!cur.isValid()) return;
    Ticket t = m_model->getTicket(cur.row());
    ticketDialog->setMode(TicketDialog::DialogMode::Edit);
    ticketDialog->loadTicket(t);
    ticketDialog->show();
    ticketDialog->raise();
    ticketDialog->activateWindow();
}

void MainWindow::on_actionDelete_triggered() {
    QModelIndex cur = ui->tableView->currentIndex();
    if (!cur.isValid()) return;

    auto result = QMessageBox::question(this, "Удаление заявки", "Вы действительно хотите удалить выбранную заявку?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (result == QMessageBox::Yes) {
        m_model->removeTicket(cur.row());
        saveData();
    }
}
void MainWindow::on_actionView_triggered() {
    QModelIndex cur = ui->tableView->currentIndex();
    if (!cur.isValid()) return;
    Ticket t = m_model->getTicket(cur.row());
    ticketDialog->setMode(TicketDialog::DialogMode::View);
    ticketDialog->loadTicket(t);
    ticketDialog->show();
    ticketDialog->raise();
    ticketDialog->activateWindow();
}

void MainWindow::saveData()
{
    if (m_repository && m_model) {
        m_repository->saveAll(m_model->getItems());
    }
}
