/**
 * @file mainwindow.cpp
 * @brief Implementation of the MainWindow class for the Calculator application.
 *
 * This file contains implementation of the main window logic,
 * including handling of button events, numbers and operation processing,
 * error handling, and keyboard shortcuts for a Qt-based calculator.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../mathlib.h"
#include <QMessageBox>
#include <QKeyEvent>


/**
 * @brief Main constructor for the calculator window.
 * Sets up the UI and connects the buttons to their respective actions.
 *
 * @param parent Parent QWidget (default: nullptr)
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);

    // Connect digit buttons to their slot
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

    // Connect operator buttons to their slot
    connect(ui->button_add, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_subtract, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_power, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_root, SIGNAL(released()), this, SLOT(binary_operation()));
}

/**
 * @brief Destructor for MainWindow. Cleans up the UI object.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Slot triggered when a digit button is pressed.
 * Handles updating the display with the pressed digit.
 */
void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    double displayNum;
    QString newResult;

    // Handle number input with operator checked
    if ((currentOperation != "null") && !typingSecondNum)
    {
        displayNum = (button->text()).toDouble();
        typingSecondNum = true;
        newResult = QString::number(displayNum, 'g', 15);
    }
    else
    {
        // Handle number input without operator checked
        if (ui->display->text().contains('.') && button->text() == "0")
        {
            newResult = ui->display->text() + button->text();
        }
        else
        {
            displayNum = (ui->display->text() + button->text()).toDouble();
            newResult = QString::number(displayNum, 'g', 15);
        }
    }

    ui->display->setText(newResult);
}

/**
 * @brief Slot triggered when the equal button is released.
 * Performs the operation based on the selected operator.
 */
void MainWindow::on_button_equal_released()
{
    double secondNum, displayNum;
    QString newResult;
    secondNum = ui->display->text().toDouble();

    // Do the corresponding operation based on the operator
    if (currentOperation == "add")
    {
        displayNum = mathlib::addition(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    }
    else if (currentOperation == "subtract")
    {
        displayNum = mathlib::subtraction(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    }
    else if (currentOperation == "multiply")
    {
        displayNum = mathlib::multiplication(firstNum, secondNum);
        newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    }
    else if (currentOperation == "divide")
    {
        try
        {
            displayNum = mathlib::division(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
        }
        catch (const std::runtime_error &err)
        {
            QMessageBox::warning(this, "Error", err.what());
        }
    }
    else if (currentOperation == "power")
    {
        try
        {
            displayNum = mathlib::power(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
        }
        catch (const std::runtime_error &err)
        {
            QMessageBox::warning(this, "Error", err.what());
        }
    }
    else if (currentOperation == "root")
    {
        try
        {
            displayNum = mathlib::root(firstNum, secondNum);
            newResult = QString::number(displayNum, 'g', 15);
            ui->display->setText(newResult);
        }
        catch (const std::runtime_error &err)
        {
            QMessageBox::warning(this, "Error", err.what());
        }
    }
    currentOperation = "null";
    typingSecondNum = false;
}

/**
 * @brief Slot triggered when the decimal point button is released.
 * Ensures that only one decimal point is present in the display.
 */
void MainWindow::on_button_point_released()
{

    if (!ui->display->text().count(QLatin1Char('.')))
    {
        ui->display->setText(ui->display->text() + ".");
    }
}

/**
 * @brief Slot triggered when the clear button is released.
 * Sets operation to null.
 * Clears the display.
 */
void MainWindow::on_button_clear_released()
{
    typingSecondNum = false;  // clear the flag
    currentOperation = "null";
    ui->display->setText("0");
}


/**
 * @brief Slot triggered when the delete button is released.
 * Deletes one character from the display.
 */
void MainWindow::on_button_del_released()
{
    if (ui->display->text().length() > 1)
    {
        ui->display->setText(ui->display->text().rightJustified(ui->display->text().length() - 1, ' ', true));
    }
    else if (ui->display->text().length() == 1)
    {
        ui->display->setText("0");
    }
}

/**
 * @brief Slot triggered when the factorial button is released.
 * Calculates the factorial of the current number.
 */
void MainWindow::on_button_factorial_released()
{
    try
    {
        double displayNum = mathlib::factorial(ui->display->text().toDouble());
        QString newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    }
    catch (const std::runtime_error &err)
    {
        QMessageBox::warning(this, "Error", err.what());
    }
}

/**
 * @brief Slot triggered when the logarithm button is released.
 * Calculates the decadic logarithm of the current number.
 */
void MainWindow::on_button_logarithm_released()
{
    try
    {
        double displayNum = mathlib::decadic_logarithm(ui->display->text().toDouble());
        QString newResult = QString::number(displayNum, 'g', 15);
        ui->display->setText(newResult);
    }
    catch (const std::runtime_error &err)
    {
        QMessageBox::warning(this, "Error", err.what());
    }
}

/**
 * @brief Slot triggered by the binary operator buttons (+, -, *, /, ^, √).
 * Sets the first number and current operation.
 * Optionally triggers equal button.
 */
void MainWindow::binary_operation()
{
    if (typingSecondNum) {
        this->on_button_equal_released();
    }

    QPushButton *button = (QPushButton *)sender();
    firstNum = ui->display->text().toDouble();

    if (button == ui->button_add) currentOperation = "add";
    else if (button == ui->button_subtract) currentOperation = "subtract";
    else if (button == ui->button_multiply) currentOperation = "multiply";
    else if (button == ui->button_divide) currentOperation = "divide";
    else if (button == ui->button_power) currentOperation = "power";
    else if (button == ui->button_root) currentOperation = "root";
    else currentOperation = "null";
}

/**
 * @brief Slot triggered when the help button is released.
 * Displays the help information for the calculator.
 */
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

/**
 * @brief Slot triggered when the sign button is released.
 * Changes the sign of the current number.
 */
void MainWindow::on_button_sign_released()
{
    double displayNum = ui->display->text().toDouble() * (-1);
    QString newResult = QString::number(displayNum, 'g', 15);
    ui->display->setText(newResult);
}

/**
 * @brief Overrides the key press event to trigger corresponding buttons
 * for keyboard input.
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Digits 0-9
    if (event->key() == Qt::Key_0)
        ui->button_0->click();
    else if (event->key() == Qt::Key_1)
        ui->button_1->click();
    else if (event->key() == Qt::Key_2)
        ui->button_2->click();
    else if (event->key() == Qt::Key_3)
        ui->button_3->click();
    else if (event->key() == Qt::Key_4)
        ui->button_4->click();
    else if (event->key() == Qt::Key_5)
        ui->button_5->click();
    else if (event->key() == Qt::Key_6)
        ui->button_6->click();
    else if (event->key() == Qt::Key_7)
        ui->button_7->click();
    else if (event->key() == Qt::Key_8)
        ui->button_8->click();
    else if (event->key() == Qt::Key_9)
        ui->button_9->click();
    // Operators
    else if (event->key() == Qt::Key_Plus)
        ui->button_add->click();
    else if (event->key() == Qt::Key_Minus)
        ui->button_subtract->click();
    else if (event->key() == Qt::Key_Asterisk)
        ui->button_multiply->click();
    else if (event->key() == Qt::Key_Slash)
        ui->button_divide->click();
    // Equals (Enter key)
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        ui->button_equal->click();
    // Clear (C key)
    else if (event->key() == Qt::Key_C)
        ui->button_clear->click();
    // delete (Backspace key)
    else if (event->key() == Qt::Key_Backspace)
        ui->button_del->click();
    // Factorial (! key)
    else if (event->key() == Qt::Key_Exclam)
        ui->button_factorial->click();
    // Power (^ key)
    else if (event->key() == Qt::Key_AsciiCircum)
        ui->button_power->click();
    // Root (R key)
    else if (event->key() == Qt::Key_R)
        ui->button_root->click();
    // Logarithm (L key)
    else if (event->key() == Qt::Key_L)
        ui->button_logarithm->click();
    // Change sign (S key)
    else if (event->key() == Qt::Key_S)
        ui->button_sign->click();
    // Decimal point (, or .)
    else if (event->key() == Qt::Key_Period || event->key() == Qt::Key_Comma)
        ui->button_point->click();
    // Help (? key or F1)
    else if (event->key() == Qt::Key_Question || event->key() == Qt::Key_F1)
        ui->button_help->click();
    else
        QMainWindow::keyPressEvent(event);
}
/** END OF FILE MAINWINDOW.CPP*/
