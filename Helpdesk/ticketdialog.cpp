#include "ticketdialog.h"
#include "ui_ticketdialog.h"

TicketDialog::TicketDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TicketDialog)
{
    ui->setupUi(this);
    connect(ui->titleEdit, &QLineEdit::textChanged, this, &TicketDialog::onFormChanged);
}

TicketDialog::~TicketDialog()
{
    delete ui;
}

void TicketDialog::setMode(DialogMode mode) {
    m_mode = mode;
    bool isEditable = (mode == DialogMode::Edit || mode == DialogMode::New);

    ui->idEdit->setReadOnly(true);
    ui->titleEdit->setReadOnly(!isEditable);
    ui->descEdit->setReadOnly(!isEditable);
    ui->createdTitle->setReadOnly(!isEditable);
    ui->statusCombo->setEnabled(isEditable);
    ui->priorityCombo->setEnabled(isEditable);
    ui->btnEdit->setVisible(mode == DialogMode::View);
    ui->btnClose->setVisible(mode == DialogMode::View);
    ui->btnSave->setVisible(isEditable);
    ui->btnSave->setDisabled(isEditable);
    ui->btnCancel->setVisible(isEditable);
    updateButtonsState();
}

void TicketDialog::loadTicket(const Ticket &ticket) {
    m_currentId = ticket.id;
    m_createdAt = ticket.createdAt;
    ui->titleEdit->setText(ticket.title);
    ui->statusCombo->setCurrentText(ticket.status);
    ui->priorityCombo->setCurrentText(ticket.priority);
    ui->descEdit->setPlainText(ticket.description);
    ui->createdTitle->setText(ticket.createdAt.toString("yyyy-MM-dd HH:mm"));
}

Ticket TicketDialog::collectTicket() const {
    Ticket t;
    t.id = m_currentId;
    t.title = ui->titleEdit->text().trimmed();
    t.status = ui->statusCombo->currentText();
    t.priority = ui->priorityCombo->currentText();
    t.description = ui->descEdit->toPlainText().trimmed();
    if (m_mode == DialogMode::New) {
        t.createdAt = QDateTime::currentDateTime();
    } else {
        t.createdAt = m_createdAt;
    }
    return t;
}

bool TicketDialog::isFormValid() const {
    return !ui->titleEdit->text().trimmed().isEmpty();
}

void TicketDialog::on_btnSave_clicked() {
    if (!isFormValid()) {
        return;
    }

    Ticket ticket = collectTicket();

    if (m_mode == DialogMode::New) {
        emit createRequested(ticket);
    } else if (m_mode == DialogMode::Edit) {
        emit updateRequested(ticket);
    }
    close();
}

void TicketDialog::on_btnClose_clicked() {
    close();
}

void TicketDialog::on_btnCancel_clicked() {
    close();
}

void TicketDialog::onFormChanged() {
    updateButtonsState();
}

void TicketDialog::updateButtonsState() {
    const bool editable = (m_mode == DialogMode::Edit || m_mode == DialogMode::New);
    ui->btnSave->setEnabled(editable && isFormValid());
}
