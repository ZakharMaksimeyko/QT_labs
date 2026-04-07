#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTable();
    connectActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTable()
{
    model = new QStandardItemModel(0, 7, this);
    model->setHorizontalHeaderLabels({"ID", "Title", "Username", "Password", "Website", "Category", "UpdatedAt"});

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::connectActions()
{
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewTriggered);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditTriggered);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteTriggered);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::onNewTriggered()
{
    int newRow = model->rowCount();
    model->insertRow(newRow);
    QModelIndex index = model->index(newRow, 1);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}

void MainWindow::onEditTriggered()
{
    QModelIndex current = ui->tableView->currentIndex();
    if (current.isValid()) {
        ui->tableView->edit(current);
    }
}

void MainWindow::onDeleteTriggered()
{
    QModelIndex current = ui->tableView->currentIndex();
    if (!current.isValid()) return;
    const auto answer = QMessageBox::question(this, "Видалення запису", "Чи дійсно ви хочете видалити цей запис?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (answer == QMessageBox::Yes) {
        model->removeRow(current.row());
    }
}
