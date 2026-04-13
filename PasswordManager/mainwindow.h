#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "databasemanager.h"
#include "repository.h"
#include "passwordtablemodel.h"
#include "passwordfilterproxymodel.h"

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
    void on_btnClear_clicked();
    void on_actionCpUs_triggered();
    void on_actionCpPs_triggered();
    void onSearchTextChanged(const QString &text);
    void onCategoryChanged(const QString &category);
    void updateEmptyState();

private:
    Ui::MainWindow *ui;
    PasswordTableModel *sourceModel;
    PasswordFilterProxyModel *proxyModel;

    DatabaseManager dbManager;
    Repository *repository;

    void setupTable();
    void connectActions();
    void loadDataToTable();
};
#endif // MAINWINDOW_H
