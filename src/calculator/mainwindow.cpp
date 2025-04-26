#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../mathlib.h"
#include <QMessageBox>
#include <QKeyEvent>

bool typingSecondNum = false;
double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
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
    QString newResult;

    if ((ui->button_add->isChecked() || ui->button_subtract->isChecked()
        || ui->button_multiply->isChecked() || ui->button_divide->isChecked()
         || ui->button_power->isChecked() || ui->button_root->isChecked()) && !typingSecondNum)
    {
        displayNum = (button->text()).toDouble();
        typingSecondNum = true;
        newResult = QString::number(displayNum, 'g', 15);

    } else {
        if (ui->display->text().contains('.') && button->text() == "0") {
            newResult = ui->display->text() + button->text();
        } else {
            displayNum = (ui->display->text() + button->text()).toDouble();
            newResult = QString::number(displayNum, 'g', 15);
        }

    }

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


void MainWindow::on_button_help_released()
{
    QMessageBox::information(this, "help",
     "Calculator Help (Version 1.0)\n\n"
     "This is a simple calculator with basic and some advanced features\n\n"
     "- Enter numbers using the digit buttons (0-9) or type the keys 0-9\n"
     "- Add a decimal point with the '.' or ',' button or key.\n"
     "- Use the operation buttons (+, -, *, /) or press the corresponding keys (+, -, *, /)\n"
     "- For exponentiation, use the '^' button or '^' key, then enter the exponent and press '='\n"
     "- For root, enter degree first, then use the '√' button or 'R' key, lastly enter base (degree has to be natural ≥ 1, base can't be negative with an even degree) \n"
     "- For decadic logarithm, use the 'log' button or 'L' key (input must be positive)\n"
     "- Press '=' or Enter to see the result\n"
     "- The '!' button or '!' key calculates the factorial (positive integers ≤ 12 only)\n"
     "- Press 'C' or the 'clear' button to clear the display\n"
     "- Press 'S' or the '+/-' button to change the number's sign\n"
     "- Press '?', F1 or the help button to show this help window\n"
     "- If an error occurs (e.g., invalid input), a message will appear.\n\n"
     "Created by team nullpointers for IVS, VUT FIT");
}

void MainWindow::on_button_sign_released()
{
    double displayNum = ui->display->text().toDouble() * (-1);
    QString newResult = QString::number(displayNum, 'g', 15);
    ui->display->setText(newResult);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    // Digits 0-9
    if (event->key() == Qt::Key_0) ui->button_0->click();
    else if (event->key() == Qt::Key_1) ui->button_1->click();
    else if (event->key() == Qt::Key_2) ui->button_2->click();
    else if (event->key() == Qt::Key_3) ui->button_3->click();
    else if (event->key() == Qt::Key_4) ui->button_4->click();
    else if (event->key() == Qt::Key_5) ui->button_5->click();
    else if (event->key() == Qt::Key_6) ui->button_6->click();
    else if (event->key() == Qt::Key_7) ui->button_7->click();
    else if (event->key() == Qt::Key_8) ui->button_8->click();
    else if (event->key() == Qt::Key_9) ui->button_9->click();
    // Operators
    else if (event->key() == Qt::Key_Plus) ui->button_add->click();
    else if (event->key() == Qt::Key_Minus) ui->button_subtract->click();
    else if (event->key() == Qt::Key_Asterisk) ui->button_multiply->click();
    else if (event->key() == Qt::Key_Slash) ui->button_divide->click();
    // Equals (Enter key)
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) ui->button_equal->click();
    // Clear (C key)
    else if (event->key() == Qt::Key_C) ui->button_clear->click();
    // delete (Backspace key)
    else if (event->key() == Qt::Key_Backspace) ui->button_del->click();
    // Factorial (! key)
    else if (event->key() == Qt::Key_Exclam) ui->button_factorial->click();
    // Power (^ key)
    else if (event->key() == Qt::Key_AsciiCircum) ui->button_power->click();
    // Root (R key)
    else if (event->key() == Qt::Key_R) ui->button_root->click();
    // Logarithm (L key)
    else if (event->key() == Qt::Key_L) ui->button_logarithm->click();
    // Change sign (S key)
    else if (event->key() == Qt::Key_S) ui->button_sign->click();
    // Decimal point (, or .)
    else if (event->key() == Qt::Key_Period || event->key() == Qt::Key_Comma) ui->button_point->click();
    // Help (? key or F1)
    else if (event->key() == Qt::Key_Question || event->key() == Qt::Key_F1) ui->button_help->click();
    else QMainWindow::keyPressEvent(event);
}


