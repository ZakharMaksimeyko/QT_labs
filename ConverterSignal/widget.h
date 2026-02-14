#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {class Widget;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    //Расстояние
    double toLength(double value, const QString &unit);
    double fromLength(double meters, const QString &unit);

    //Вес
    double toMass(double value, const QString &unit);
    double fromMass(double kilograms, const QString &unit);

    //Температура
    double toTemp(double value, const QString &unit);
    double fromTemp(double celsius, const QString &unit);

    void InputLen_changed();
    void InputMass_changed();
    void InputTemp_changed();

    void ResultLen_changed();
    void ResultMass_changed();
    void ResultTemp_changed();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
