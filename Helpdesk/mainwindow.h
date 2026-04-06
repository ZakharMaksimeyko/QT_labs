#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ticketdialog.h"
#include "tickettablemodel.h"
#include "csvticketrepository.h"
#include "ticketfilterproxymodel.h"

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
    void on_actionView_triggered();
    void on_actionRefresh_triggered();
    void updateActions();
    void on_actionEdit_triggered();
    void on_actionDelete_triggered();
    void on_btnClear_clicked();
    void saveData();
    void updateEmptyState();

private:
    Ui::MainWindow *ui;
    TicketDialog *ticketDialog = nullptr;
    TicketTableModel *m_model = nullptr;
    CsvTicketRepository *m_repository = nullptr;
    TicketFilterProxyModel *m_proxyModel = nullptr;
};
#endif // MAINWINDOW_H
