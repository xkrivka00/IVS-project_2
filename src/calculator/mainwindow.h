#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::Calculator *ui;

private slots:
    void digit_pressed();
    void binary_operation();

    void on_button_point_released();
    void on_button_equal_released();
    void on_button_clear_released();
    void on_button_del_released();
    void on_button_factorial_released();
    void on_button_logarithm_released();
    void on_button_help_released();
};
#endif // MAINWINDOW_H
