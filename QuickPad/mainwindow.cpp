#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionNew->setShortcuts(QKeySequence::New);
    ui->actionOpen->setShortcuts(QKeySequence::Open);
    ui->actionSave->setShortcuts(QKeySequence::Save);
    ui->actionSave_As->setShortcuts(QKeySequence::SaveAs);
    ui->actionExit->setShortcuts(QKeySequence::Quit);

    connect(ui->actionCut, &QAction::triggered, ui->textEditor, &QPlainTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEditor, &QPlainTextEdit::copy);
    connect(ui->actionPast, &QAction::triggered, ui->textEditor, &QPlainTextEdit::paste);
    connect(ui->actionSelect_All, &QAction::triggered, ui->textEditor, &QPlainTextEdit::selectAll);
    connect(ui->textEditor->document(), &QTextDocument::contentsChanged, this, &MainWindow::documentModified);
    connect(ui->textEditor, &QPlainTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);
    connect(ui->textEditor, &QPlainTextEdit::copyAvailable, ui->actionCut, &QAction::setEnabled);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::on_actionAbout_triggered);

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);

    setCurrentFile("");

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::maybeSave()
{
    if (!ui->textEditor->document()->isModified())
        return true;

    const QMessageBox::StandardButton ret = QMessageBox::warning(this, tr("QuickPad"), tr("Документ було змінено.\n" "Бажаєте зберегти зміни?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    switch (ret) {
    case QMessageBox::Save:
        return on_actionSave_triggered(), true;
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("QuickPad"), tr("Не вдалося відкрити файл %1:\n%2.") .arg(QFileInfo(fileName).fileName(), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

    ui->textEditor->setPlainText(in.readAll());

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    ui->statusbar->showMessage(tr("Файл відкрито"), 2000);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QString errorMessage;

    QFile file(fileName);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
#ifndef QT_NO_CURSOR
        QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

        out << ui->textEditor->toPlainText();

#ifndef QT_NO_CURSOR
        QApplication::restoreOverrideCursor();
#endif

        setCurrentFile(fileName);
        ui->statusbar->showMessage(tr("Файл збережено"), 2000);
        return true;
    }

    QMessageBox::warning(this, tr("QuickPad"), tr("Не вдалося зберегти файл %1:\n%2.") .arg(QFileInfo(fileName).fileName(), file.errorString()));
    return false;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    currentFile = fileName;
    ui->textEditor->document()->setModified(false);
    setWindowModified(false);

    QString shownName = currentFile;
    if (currentFile.isEmpty())
        shownName = "untitled.txt";

    setWindowFilePath(shownName);
    setWindowTitle(QFileInfo(shownName).fileName() + "[*] - QuickPad");
}

void MainWindow::documentModified()
{
    setWindowModified(ui->textEditor->document()->isModified());
}

void MainWindow::on_actionNew_triggered()
{
    if (maybeSave()) {
        ui->textEditor->clear();
        setCurrentFile("");
        ui->textEditor->setFocus();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);

        ui->textEditor->setFocus();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (currentFile.isEmpty()) {
        on_actionSaveAs_triggered();
    } else {
        saveFile(currentFile);
    }
    ui->textEditor->setFocus();
}

void MainWindow::on_actionSaveAs_triggered()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    if (dialog.exec() != QDialog::Accepted)
        return;

    saveFile(dialog.selectedFiles().constFirst());
    ui->textEditor->setFocus();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("Про QuickPad"), tr("<h3>QuickPad v1.0</h3>" "<p>Це простий текстовий редактор, створений на базі Qt.</p>"));
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
