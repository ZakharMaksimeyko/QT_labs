#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QFutureWatcher>
#include <QtConcurrent>
#include "databasemanager.h"
#include "repository.h"
#include "passwordtablemodel.h"
#include "passwordfilterproxymodel.h"
#include "passwordleakchecker.h"

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
    void checkSelectedPassword();
    void onLeakCheckCompleted(bool isCompromised, int count);
    void onLeakCheckFailed(const QString &errorMessage);
    void checkAllPasswords();
    void onBatchCheckFinished();

    Q_INVOKABLE void updateBatchProgress(int current);

private:
    Ui::MainWindow *ui;
    PasswordTableModel *sourceModel;
    PasswordFilterProxyModel *proxyModel;
    PasswordLeakChecker *leakChecker;
    QFutureWatcher<BatchCheckResult> *batchWatcher;
    DatabaseManager dbManager;
    Repository *repository;

    void setupTable();
    void connectActions();
    void loadDataToTable();
};
#endif // MAINWINDOW_H
