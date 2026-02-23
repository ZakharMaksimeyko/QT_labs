#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupLessons();
    ui->stackedWidget->setCurrentIndex(0);
    ui->labelPassedText->setStyleSheet("background-color: yellow; color: black;");
    ui->labelPreviousLine->setStyleSheet("background-color: yellow; color: black;");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupLessons()
{
    ui->selectText->clear();
    ui->selectText->addItem("Starter Text",
                           "The quick brown fox jumps over the lazy dog.\n"
                           "Hello world, this is a test lesson.\n"
                           "Keep practicing to improve your speed!");
    ui->selectText->addItem("Python Code Sample",
                           "def factorial(n):\n"
                           "    if n == 0:\n"
                           "        return 1\n"
                           "    else:\n"
                           "        return n * factorial(n-1)");
    ui->selectText->addItem("Lorem Ipsum",
                           "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
                           "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
}

void MainWindow::on_btnStart_clicked()
{
    QString selectedLessonText = ui->selectText->currentData().toString();

    m_model.loadLesson(selectedLessonText);
    updateTrainingUI();

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::updateTrainingUI()
{
    ui->labelPreviousLine->setText(m_model.getPreviousLine());
    ui->labelPassedText->setText(m_model.getPassedText());
    ui->labelRemainingText->setText(m_model.getRemainingText());

    if (m_model.isFinished()) {
        ui->labelRemainingText->setText("--- ТРЕНУВАННЯ ЗАКІНЧЕНО ---");
    }
}

void MainWindow::on_btnTestAdvance_clicked()
{
    m_model.advanceChar();
    updateTrainingUI();
}
