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

    void on_btnConvertLen_clicked();
    void on_btnConvertMass_clicked();
    void on_btnConvertTemp_clicked();

    void Len_changed();
    void Mass_changed();
    void Temp_changed();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
