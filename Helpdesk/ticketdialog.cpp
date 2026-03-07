#include "ticketdialog.h"
#include "ui_ticketdialog.h"

TicketDialog::TicketDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TicketDialog)
{
    ui->setupUi(this);
}

TicketDialog::~TicketDialog()
{
    delete ui;
}

void TicketDialog::setMode(DialogMode mode) {
    bool isEditable = (mode == DialogMode::Edit || mode == DialogMode::New);

    ui->titleEdit->setReadOnly(!isEditable);
    ui->descEdit->setReadOnly(!isEditable);

    ui->statusCombo->setEnabled(isEditable);
    ui->priorityCombo->setEnabled(isEditable);

    if (mode == DialogMode::View) {
        ui->btnEdit->setVisible(true);
        ui->btnClose->setVisible(true);

        ui->btnSave->setVisible(false);
        ui->btnCancel->setVisible(false);
    } else {
        ui->btnEdit->setVisible(false);
        ui->btnClose->setVisible(false);

        ui->btnSave->setVisible(true);
        ui->btnCancel->setVisible(true);
    }
}
