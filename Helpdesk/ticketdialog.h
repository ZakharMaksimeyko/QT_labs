#ifndef TICKETDIALOG_H
#define TICKETDIALOG_H

#include <QDialog>
#include "ticket.h"

namespace Ui {
class TicketDialog;
}

class TicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketDialog(QWidget *parent = nullptr);
    ~TicketDialog();

    enum class DialogMode {
        View,
        Edit,
        New
    };

    void setMode(DialogMode mode);
    void loadTicket(const Ticket &ticket);

signals:
    void createRequested(const Ticket &ticket);
    void updateRequested(const Ticket &ticket);

private slots:
    void on_btnSave_clicked();
    void on_btnClose_clicked();
    void on_btnCancel_clicked();
    void onFormChanged();

private:
    Ui::TicketDialog *ui;
    DialogMode m_mode = DialogMode::New;
    int m_currentId = -1;
    QDateTime m_createdAt;
    Ticket collectTicket() const;
    bool isFormValid() const;
    void updateButtonsState();
};

#endif // TICKETDIALOG_H
