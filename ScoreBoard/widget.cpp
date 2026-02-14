<<<<<<< HEAD
#include "widget.h"
#include "ui_widget.h"
#include "iostream"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnAdd_A, &QPushButton::clicked, this, &Widget::increaseA);
    connect(ui->btnMinus_A, &QPushButton::clicked, this, &Widget::decreaseA);
    connect(ui->btnAdd_B, &QPushButton::clicked, this, &Widget::increaseB);
    connect(ui->btnMinus_B, &QPushButton::clicked, this, &Widget::decreaseB);
    connect(ui->btnReset, &QPushButton::clicked, this, &Widget::resetScores);

    updateScores();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::increaseA()
{
    Score_A++;
    updateScores();
    std::cout << "+A";
}

void Widget::decreaseA()
{
    if (Score_A > 0)
        Score_A--;
    updateScores();
    std::cout << "-A";

}

void Widget::increaseB()
{
    Score_B++;
    updateScores();
    std::cout << "+B";
}

void Widget::decreaseB()
{
    if (Score_B > 0)
        Score_B--;
    updateScores();
    std::cout << "-B";
}

void Widget::resetScores()
{
    Score_A = 0;
    Score_B = 0;
    updateScores();
    std::cout << "score reseted";
}

void Widget::updateScores()
{
    ui->Score_A->setText(QString::number(Score_A));
    ui->Score_B->setText(QString::number(Score_B));
    std::cout << "score updated";
}
=======
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
>>>>>>> bf42604 (First Commit)
