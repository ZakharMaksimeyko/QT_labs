#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QClipboard>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (dbManager.open("vault.db")) {
        dbManager.initializeSchema();
    }
    repository = new Repository(dbManager.database());
    sourceModel = new PasswordTableModel(repository, this);
    proxyModel = new PasswordFilterProxyModel(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(1);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->comboSort, &QComboBox::currentTextChanged, this, &MainWindow::onCategoryChanged);
    connect(proxyModel, &QAbstractItemModel::rowsInserted, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::rowsRemoved, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::layoutChanged, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::modelReset, this, &MainWindow::updateEmptyState);
    setupTable();
    loadDataToTable();
}

MainWindow::~MainWindow()
{
    delete repository;
    delete ui;
}

void MainWindow::setupTable()
{
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::SelectedClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::loadDataToTable()
{
    sourceModel->setItems(repository->loadAll());
    updateEmptyState();
}

void MainWindow::onSearchTextChanged(const QString &text)
{
    proxyModel->setTextFilter(text);
}

void MainWindow::onCategoryChanged(const QString &category)
{
    proxyModel->setCategoryFilter(category);
}

void MainWindow::updateEmptyState()
{
    if (ui->emptyStateLabel) {
        const bool empty = (proxyModel->rowCount() == 0);
        ui->emptyStateLabel->setVisible(empty);
    }
}

void MainWindow::on_actionNew_triggered()
{
    PasswordRecord newRecord;
    newRecord.title = "New Entry";
    if (ui->comboSort && ui->comboSort->currentText() != "All") {
        newRecord.category = ui->comboSort->currentText();
    }
    newRecord.updatedAt = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    if (repository->insert(newRecord)) {
        loadDataToTable();
        QModelIndex sourceIndex = sourceModel->index(sourceModel->rowCount() - 1, 1);
        QModelIndex proxyIndex = proxyModel->mapFromSource(sourceIndex);
        ui->tableView->setCurrentIndex(proxyIndex);
        ui->tableView->edit(proxyIndex);
    }
}

void MainWindow::on_actionEdit_triggered()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();
    if (proxyIndex.isValid()) {
        if (proxyIndex.column() == 0) {
            proxyIndex = proxyModel->index(proxyIndex.row(), 1);
            ui->tableView->setCurrentIndex(proxyIndex);
        }
        if (proxyIndex.isValid()) {
            ui->tableView->setCurrentIndex(proxyIndex);
            ui->tableView->edit(proxyIndex);
        }
    }
}

void MainWindow::on_actionDelete_triggered()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();
    if (!proxyIndex.isValid()) return;
    const auto answer = QMessageBox::question(this, "Видалення запису", "Чи дійсно ви хочете видалити цей запис?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (answer == QMessageBox::Yes) {
        QModelIndex sourceIndex = proxyModel->mapToSource(proxyIndex);
        int sourceRow = sourceIndex.row();
        int id = sourceModel->itemAt(sourceRow).id;
        if (repository->remove(id)) {
            loadDataToTable();
        }
    }
}

void MainWindow::on_actionCpPs_triggered()
{

    QModelIndex password = ui->tableView->currentIndex();
    if (password.isValid()) {
        password = proxyModel->index(password.row(), 3);
        QString passwordText = proxyModel->data(password, Qt::DisplayRole).toString();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(passwordText);
    }
}

void MainWindow::on_actionCpUs_triggered()
{

    QModelIndex password = ui->tableView->currentIndex();
    if (password.isValid()) {
        password = proxyModel->index(password.row(), 2);
        QString passwordText = proxyModel->data(password, Qt::DisplayRole).toString();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(passwordText);
    }
}

void MainWindow::on_btnClear_clicked()
{
    ui->lineEdit->setText("");
}
