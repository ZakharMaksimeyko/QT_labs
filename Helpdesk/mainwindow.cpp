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
    m_proxyModel = new TicketFilterProxyModel(this);
    m_proxyModel->setSourceModel(m_model);
    ui->tableView->setModel(m_proxyModel);
    ui->tableView->setSortingEnabled(true);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, [this](const QString &text) {
        m_proxyModel->setTextFilter(text);
        updateEmptyState();
    });
    connect(ui->comboStatus, &QComboBox::currentTextChanged, this, [this](const QString &status) {
        m_proxyModel->setStatusFilter(status);
        updateEmptyState();
    });
    connect(ui->comboPriority, &QComboBox::currentTextChanged, this, [this](const QString &priority) {
        m_proxyModel->setPriorityFilter(priority);
        updateEmptyState();
    });
    connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::on_actionEdit_triggered);

    auto *header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(TicketTableModel::TitleCol, QHeaderView::Stretch);
    header->setSectionResizeMode(TicketTableModel::IdCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::PriorityCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::StatusCol, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(TicketTableModel::CreatedAtCol, QHeaderView::ResizeToContents);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::updateActions);
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

    QModelIndex sourceIndex = m_proxyModel->mapToSource(cur);
    Ticket t = m_model->getTicket(sourceIndex.row());

    ticketDialog->setMode(TicketDialog::DialogMode::Edit);
    ticketDialog->loadTicket(t);
    ticketDialog->show();
    ticketDialog->raise();
    ticketDialog->activateWindow();
}
void MainWindow::on_actionDelete_triggered() {
    QModelIndex cur = ui->tableView->currentIndex();
    if (!cur.isValid()) return;

    QModelIndex sourceIndex = m_proxyModel->mapToSource(cur);

    auto result = QMessageBox::question(this, "Удаление заявки", "Вы действительно хотите удалить выбранную заявку?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (result == QMessageBox::Yes) {
        m_model->removeTicket(cur.row());
        saveData();
        updateEmptyState();
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

void MainWindow::on_actionRefresh_triggered() {
    QModelIndex cur = ui->tableView->currentIndex();
    if (!cur.isValid()) return;

    updateActions();
}

void MainWindow::on_btnClear_clicked(){
    ui->lineEdit->setText(" ");
    updateActions();
}


void MainWindow::saveData()
{
    if (m_repository && m_model) {
        m_repository->saveAll(m_model->getItems());
    }
}

void MainWindow::updateEmptyState() {
    bool empty = (m_proxyModel->rowCount() == 0);
    updateActions();
}
