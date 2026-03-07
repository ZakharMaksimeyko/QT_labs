#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *model = new QStandardItemModel(0, 5, this);
    model->setHorizontalHeaderLabels({"ID", "Title", "Status", "Priority", "Created At"});
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    ticketDialog->raise(); // Виводить вікно на передній план, якщо воно вже було відкрите
    ticketDialog->activateWindow();
}
