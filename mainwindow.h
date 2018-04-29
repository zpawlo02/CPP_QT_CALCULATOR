#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void function_plus();

private slots:
    void digit_pressed();
    void on_pushButton_comma_released();
    void unary_operation_pressed();

    void on_pushButton_cleaner_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();

};

#endif // MAINWINDOW_H
