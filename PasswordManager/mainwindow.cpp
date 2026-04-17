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
    if(ui->progressBar) {
        ui->progressBar->setVisible(false);
    }
    repository = new Repository(dbManager.database());
    sourceModel = new PasswordTableModel(repository, this);
    proxyModel = new PasswordFilterProxyModel(this);
    leakChecker = new PasswordLeakChecker(this);
    batchWatcher = new QFutureWatcher<BatchCheckResult>(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(1);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->comboSort, &QComboBox::currentTextChanged, this, &MainWindow::onCategoryChanged);
    connect(ui->actionCheckPassword, &QAction::triggered, this, &MainWindow::checkSelectedPassword);
    connect(ui->actionCheckAll, &QAction::triggered, this, &MainWindow::checkAllPasswords);
    connect(proxyModel, &QAbstractItemModel::rowsInserted, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::rowsRemoved, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::layoutChanged, this, &MainWindow::updateEmptyState);
    connect(proxyModel, &QAbstractItemModel::modelReset, this, &MainWindow::updateEmptyState);
    connect(leakChecker, &PasswordLeakChecker::checkCompleted, this, &MainWindow::onLeakCheckCompleted);
    connect(leakChecker, &PasswordLeakChecker::checkFailed, this, &MainWindow::onLeakCheckFailed);
    connect(batchWatcher, &QFutureWatcher<BatchCheckResult>::finished, this, &MainWindow::onBatchCheckFinished);

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

void MainWindow::checkSelectedPassword()
{
    QModelIndex proxyIndex = ui->tableView->currentIndex();
    if (!proxyIndex.isValid()) {
        QMessageBox::warning(this, "Увага", "Виберіть запис для перевірки!");
        return;
    }
    QModelIndex sourceIndex = proxyModel->mapToSource(proxyIndex);
    QString password = sourceModel->itemAt(sourceIndex.row()).password;
    if (password.isEmpty()) {
        QMessageBox::information(this, "Перевірка", "Пароль порожній, перевіряти нічого.");
        return;
    }

    ui->actionCheckPassword->setEnabled(false);
    statusBar()->showMessage("Перевірка пароля у базах витоків...");
    leakChecker->checkPassword(password);
}

void MainWindow::onLeakCheckCompleted(bool isCompromised, int count)
{
    ui->actionCheckPassword->setEnabled(true);
    statusBar()->clearMessage();
    if (isCompromised) {
        QString msg = QString("Небезпека!\nЦей пароль було знайдено у злитих базах %1 разів!\nНегайно змініть його!").arg(count);
        QMessageBox::critical(this, "Перевірка завершена", msg);
    } else {
        QMessageBox::information(this, "Безпечно", "Чудово! Цей пароль не знайдено у відомих базах витоків.");
    }
}

void MainWindow::onLeakCheckFailed(const QString &errorMessage)
{
    ui->actionCheckPassword->setEnabled(true);
    statusBar()->clearMessage();
    QMessageBox::warning(this, "Помилка перевірки", errorMessage);
}

void MainWindow::checkAllPasswords()
{
    QList<QString> passwords;
    for (int i = 0; i < sourceModel->rowCount(); ++i) {
        passwords.append(sourceModel->itemAt(i).password);
    }
    if (passwords.isEmpty()) {
        QMessageBox::information(this, "Увага", "Немає записів для перевірки.");
        return;
    }
    ui->actionCheckAll->setEnabled(false);
    ui->progressBar->setRange(0, passwords.size());
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);
    statusBar()->showMessage("Виконується масова перевірка паролів...");
    QFuture<BatchCheckResult> future = QtConcurrent::run(PasswordLeakChecker::runBatchCheck, passwords, this);
    batchWatcher->setFuture(future);
}

void MainWindow::updateBatchProgress(int current)
{
    if (ui->progressBar) {
        ui->progressBar->setValue(current);
    }
}

void MainWindow::onBatchCheckFinished()
{
    BatchCheckResult result = batchWatcher->result();
    ui->actionCheckAll->setEnabled(true);
    if (ui->progressBar) ui->progressBar->setVisible(false);
    statusBar()->clearMessage();
    QString message = QString("Перевірку завершено!\n\nВсього перевірено: %1\nЗлитих паролів знайдено: %2").arg(result.checked).arg(result.compromised);
    if (result.compromised > 0) {
        QMessageBox::warning(this, "Результати масової перевірки", message);
    } else {
        QMessageBox::information(this, "Усе безпечно!", message);
    }
}
