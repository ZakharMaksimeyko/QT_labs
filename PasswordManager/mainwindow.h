#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "databasemanager.h"
#include "repository.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionEdit_triggered();
    void on_actionDelete_triggered();
    void onItemChanged(QStandardItem *item);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;

    DatabaseManager dbManager;
    Repository *repository;

    void setupTable();
    void connectActions();
    void loadDataToTable();
};
#endif // MAINWINDOW_H
