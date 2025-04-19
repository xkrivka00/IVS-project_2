#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../mathlib.h"
#include <QMessageBox>

bool typingSecondNum = false;
double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->button_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->button_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->button_add, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_subtract, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_power, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_root, SIGNAL(released()), this, SLOT(binary_operation()));

    ui->button_add->setCheckable(true);
    ui->button_subtract->setCheckable(true);
    ui->button_multiply->setCheckable(true);
    ui->button_divide->setCheckable(true);
    ui->button_power->setCheckable(true);
    ui->button_root->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double displayNum;

    if ((ui->button_add->isChecked() || ui->button_subtract->isChecked()
        || ui->button_multiply->isChecked() || ui->button_divide->isChecked()
         || ui->button_power->isChecked() || ui->button_root->isChecked()) && !typingSecondNum)
    {
        displayNum = (button->text()).toDouble();
        typingSecondNum = true;
    } else {
        displayNum = (ui->display->text() + button->text()).toDouble();
    }

    QString newResult = QString::number(displayNum, 'g', 15);
    ui->display->setText(newResult);
}

void MainWindow::on_button_equal_released()
{
    double secondNum, displayNum;
    QString newResult;
    secondNum = ui->display->text().toDouble();

    if (ui->button_add->isChecked()) {
        displayNum = mathlib::addition(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
        ui->button_add->setChecked(false);

    } else if (ui->button_subtract->isChecked()) {
        displayNum = mathlib::subtraction(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
        ui->button_subtract->setChecked(false);

    } else if (ui->button_multiply->isChecked()) {
        displayNum = mathlib::multiplication(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
        ui->button_multiply->setChecked(false);

    } else if (ui->button_divide->isChecked()) {
        try {
            displayNum = mathlib::division(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
            ui->button_divide->setChecked(false);
        } catch (const std::runtime_error& err) {
            QMessageBox::warning(this, "Error", err.what());
        }
    } else if (ui->button_power->isChecked()) {
        try {
            displayNum = mathlib::power(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
            ui->button_power->setChecked(false);
        } catch (const std::runtime_error& err) {
            QMessageBox::warning(this, "Error", err.what());
        }

    } else if (ui->button_root->isChecked()) {
        try {
            displayNum = mathlib::root(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
            ui->button_root->setChecked(false);
        } catch (const std::runtime_error& err) {
            QMessageBox::warning(this, "Error", err.what());
        }
    }

    typingSecondNum = false;
}

void MainWindow::on_button_point_released()
{

    if (!ui->display->text().count(QLatin1Char('.'))) {
        ui->display->setText(ui->display->text() + ".");
    }

}


void MainWindow::on_button_clear_released()
{
    ui->display->setText("0");
}


void MainWindow::on_button_del_released()
{
    if (ui->display->text().length() > 1) {
        ui->display->setText(ui->display->text().rightJustified(ui->display->text().length()-1, ' ', true));
    } else if (ui->display->text().length() == 1) {
        ui->display->setText("0");
    }
}


void MainWindow::on_button_factorial_released()
{
    try {
        double displayNum = mathlib::factorial(ui->display->text().toDouble());
        QString newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    } catch (const std::runtime_error& err) {
        QMessageBox::warning(this, "Error", err.what());
    }
}


void MainWindow::on_button_logarithm_released()
{
    try {
        double displayNum = mathlib::decadic_logarithm(ui->display->text().toDouble());
        QString newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    } catch (const std::runtime_error& err) {
        QMessageBox::warning(this, "Error", err.what());
    }
}


void MainWindow::binary_operation()
{
    QPushButton *button = (QPushButton*)sender();

    firstNum = ui->display->text().toDouble();

    button->setChecked(true);
}

