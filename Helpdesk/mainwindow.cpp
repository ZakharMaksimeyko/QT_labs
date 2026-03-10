#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered() {
    if (!ticketDialog) {
        ticketDialog = new TicketDialog(this);
    }
    ticketDialog->setMode(TicketDialog::DialogMode::New);
    ticketDialog->show();
    ticketDialog->raise();
    ticketDialog->activateWindow();
}

void MainWindow::updateActions()
{
    bool hasSelection = ui->tableView->selectionModel()->hasSelection();
    ui->actionView->setEnabled(hasSelection);
    ui->actionEdit->setEnabled(hasSelection);
    ui->actionDelete->setEnabled(hasSelection);
}
