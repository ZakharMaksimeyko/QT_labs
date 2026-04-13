#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    if (dbManager.open("vault.db")) {
        dbManager.initializeSchema();
    }
    repository = new Repository(dbManager.database());
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
    model = new QStandardItemModel(0, 7, this);
    model->setHorizontalHeaderLabels({"ID", "Title", "Username", "Password", "Website", "Category", "UpdatedAt"});

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    connect(model, &QStandardItemModel::itemChanged, this, &MainWindow::onItemChanged);
}

void MainWindow::loadDataToTable()
{
    disconnect(model, &QStandardItemModel::itemChanged, this, &MainWindow::onItemChanged);
    model->removeRows(0, model->rowCount());

    QList<PasswordRecord> records = repository->loadAll();
    for (const auto& record : records) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(record.id));
        rowItems << new QStandardItem(record.title);
        rowItems << new QStandardItem(record.username);
        rowItems << new QStandardItem(record.password);
        rowItems << new QStandardItem(record.website);
        rowItems << new QStandardItem(record.category);
        rowItems << new QStandardItem(record.updatedAt);
        rowItems[0]->setFlags(rowItems[0]->flags() & ~Qt::ItemIsEditable);

        model->appendRow(rowItems);
    }

    connect(model, &QStandardItemModel::itemChanged, this, &MainWindow::onItemChanged);
}

void MainWindow::on_actionNew_triggered()
{
    PasswordRecord newRecord;
    newRecord.title = "New Entry";
    newRecord.updatedAt = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    if (repository->insert(newRecord)) {
        loadDataToTable();
        QModelIndex index = model->index(model->rowCount() - 1, 1);
        ui->tableView->setCurrentIndex(index);
        ui->tableView->edit(index);
    }
}

void MainWindow::on_actionEdit_triggered()
{
    QModelIndex current = ui->tableView->currentIndex();
    if (current.isValid()) {
        if (current.column() == 0) {
            current = model->index(current.row(), 1);
            ui->tableView->setCurrentIndex(current);
        }
        ui->tableView->edit(current);
    }
}

void MainWindow::on_actionDelete_triggered()
{
    QModelIndex current = ui->tableView->currentIndex();
    if (!current.isValid()) return;
    const auto answer = QMessageBox::question(this, "Видалення запису", "Чи дійсно ви хочете видалити цей запис?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (answer == QMessageBox::Yes) {
        int id = model->item(current.row(), 0)->text().toInt();
        if (repository->remove(id)) {
            loadDataToTable();
        }
    }
}

void MainWindow::onItemChanged(QStandardItem *item)
{
    int row = item->row();

    PasswordRecord record;
    record.id = model->item(row, 0)->text().toInt();
    record.title = model->item(row, 1) ? model->item(row, 1)->text() : "";
    record.username = model->item(row, 2) ? model->item(row, 2)->text() : "";
    record.password = model->item(row, 3) ? model->item(row, 3)->text() : "";
    record.website = model->item(row, 4) ? model->item(row, 4)->text() : "";
    record.category = model->item(row, 5) ? model->item(row, 5)->text() : "";
    record.updatedAt = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    repository->update(record);

    model->blockSignals(true);
    if(model->item(row, 6)) model->item(row, 6)->setText(record.updatedAt);
    model->blockSignals(false);
}
