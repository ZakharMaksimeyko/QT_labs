#ifndef TICKETDIALOG_H
#define TICKETDIALOG_H

#include <QDialog>

namespace Ui {
class TicketDialog;
}

class TicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketDialog(QWidget *parent = nullptr);
    ~TicketDialog();

    // Наш enum для управления состояниями окна
    enum class DialogMode {
        View,
        Edit,
        New
    };

    // Метод для переключения интерфейса
    void setMode(DialogMode mode);

private:
    Ui::TicketDialog *ui;
};

#endif // TICKETDIALOG_H
