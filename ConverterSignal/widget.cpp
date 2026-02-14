#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->LenInput, &QDoubleSpinBox::textChanged,
            this, &Widget::InputLen_changed);
    connect(ui->MassInput, &QDoubleSpinBox::textChanged,
            this, &Widget::InputMass_changed);
    connect(ui->TempInput, &QDoubleSpinBox::textChanged,
            this, &Widget::InputTemp_changed);
    connect(ui->LenResult, &QDoubleSpinBox::textChanged,
            this, &Widget::ResultLen_changed);
    connect(ui->MassResult, &QDoubleSpinBox::textChanged,
            this, &Widget::ResultMass_changed);
    connect(ui->TempResult, &QDoubleSpinBox::textChanged,
            this, &Widget::ResultTemp_changed);
    connect(ui->InputBoxLen, &QComboBox::currentTextChanged,
            this, &Widget::InputLen_changed);
    connect(ui->InputBoxMass, &QComboBox::currentTextChanged,
            this, &Widget::InputMass_changed);
    connect(ui->InputBoxTemp, &QComboBox::currentTextChanged,
            this, &Widget::InputTemp_changed);
    connect(ui->ResultBoxLen, &QComboBox::currentTextChanged,
            this, &Widget::ResultLen_changed);
    connect(ui->ResultBoxMass, &QComboBox::currentTextChanged,
            this, &Widget::ResultMass_changed);
    connect(ui->ResultBoxTemp, &QComboBox::currentTextChanged,
            this, &Widget::ResultTemp_changed);


}

Widget::~Widget()
{
    delete ui;
}

double Widget::toLength(double value, const QString &unit)
{
    if (unit == "meters (m)")      return value;
    if (unit == "kilometers (km)") return value * 1000.0;
    if (unit == "inches (in)")     return value * 0.0254;
    if (unit == "feet (ft)")       return value * 0.3048;
    if (unit == "miles (mi)")      return value * 1609.34;

    return value;
}

double Widget::fromLength(double meters, const QString &unit)
{
    if (unit == "meters (m)")      return meters;
    if (unit == "kilometers (km)") return meters / 1000.0;
    if (unit == "inches (in)")     return meters / 0.0254;
    if (unit == "feet (ft)")       return meters / 0.3048;
    if (unit == "miles (mi)")      return meters / 1609.34;

    return meters;
}

double Widget::toMass(double value, const QString &unit)
{
    if (unit == "kilograms (kg)") return value;
    if (unit == "pounds (lb)")    return value * 0.453592;
    if (unit == "ounces (oz)")    return value * 0.0283495;
    return value;
}

double Widget::fromMass(double kilograms, const QString &unit)
{
    if (unit == "kilograms (kg)") return kilograms;
    if (unit == "pounds (lb)")    return kilograms / 0.453592;
    if (unit == "ounces (oz)")    return kilograms / 0.0283495;

    return kilograms;
}

double Widget::toTemp(double value, const QString &unit)
{
    if (unit == "Celsius (°C)")    return value;
    if (unit == "Fahrenheit (°F)") return (value - 32.0) * 5.0 / 9.0;
    if (unit == "Kelvin (K)")      return value - 273.15;

    return value;
}

double Widget::fromTemp(double celsius, const QString &unit)
{

    if (unit == "Celsius (°C)")    return celsius;
    if (unit == "Fahrenheit (°F)") return (celsius * 9.0 / 5.0) + 32.0;
    if (unit == "Kelvin (K)")      return celsius + 273.15;

    return celsius;
}

void Widget::InputLen_changed()
{
    bool ok;
    double val = ui->LenInput->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->InputBoxLen->currentText();
    QString unitTo = ui->ResultBoxLen->currentText();

    double meters = toLength(val, unitFrom);
    double result = fromLength(meters, unitTo);

    ui->LenResult->setValue(result);
}

void Widget::InputMass_changed()
{
    bool ok;
    double val = ui->MassInput->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->InputBoxMass->currentText();
    QString unitTo = ui->ResultBoxMass->currentText();

    double kilograms = toMass(val, unitFrom);
    double result = fromMass(kilograms, unitTo);

    ui->MassResult->setValue(result);
}


void Widget::InputTemp_changed()
{
    bool ok;
    double val = ui->TempInput->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->InputBoxTemp->currentText();
    QString unitTo = ui->ResultBoxTemp->currentText();

    double celsius = toTemp(val, unitFrom);
    double result = fromTemp(celsius, unitTo);

    ui->TempResult->setValue(result);
}

void Widget::ResultLen_changed()
{
    bool ok;
    double val = ui->LenResult->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->ResultBoxLen->currentText();
    QString unitTo = ui->InputBoxLen->currentText();

    double meters = toLength(val, unitFrom);
    double result = fromLength(meters, unitTo);

    ui->LenInput->setValue(result);
}

void Widget::ResultMass_changed()
{
    bool ok;
    double val = ui->MassResult->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->ResultBoxMass->currentText();
    QString unitTo = ui->InputBoxMass->currentText();

    double kilograms = toMass(val, unitFrom);
    double result = fromMass(kilograms, unitTo);

    ui->MassInput->setValue(result);
}

void Widget::ResultTemp_changed()
{
    bool ok;
    double val = ui->TempResult->text().replace(",", ".").toDouble(&ok);

    if (!ok) return;

    QString unitFrom = ui->ResultBoxTemp->currentText();
    QString unitTo = ui->InputBoxTemp->currentText();

    double celsius = toTemp(val, unitFrom);
    double result = fromTemp(celsius, unitTo);

    ui->TempInput->setValue(result);
}
