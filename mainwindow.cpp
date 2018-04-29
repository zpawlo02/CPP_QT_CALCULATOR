#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstnum;
bool user_is_typing_second_number = false;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plus_minus, SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_precent, SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_multiply, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_plus, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()),this,SLOT(binary_operation_pressed()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double label_number;
    QString newLabel;

    if((ui->pushButton_plus->isChecked() ||
       ui->pushButton_minus->isChecked() ||
       ui->pushButton_multiply->isChecked() ||
       ui->pushButton_divide->isChecked() )  && (!user_is_typing_second_number) )
    {
       label_number = button->text().toDouble();
       user_is_typing_second_number = true;
       newLabel = QString::number(label_number,'g',15);
    }

    else{

        if(ui->label->text().contains(".") && button->text() == "0"){
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            label_number = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(label_number,'g',15);
        }


    }


    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_comma_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton *button = (QPushButton*) sender();
    double label_number;
    QString newLabel;


    if(button->text() == "+/-")
    {
        label_number = ui->label->text().toDouble();
        label_number *= -1;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
    }

    if(button->text() == "%")
    {
        label_number = ui->label->text().toDouble();
        label_number *= 0.01;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
    }


}

void MainWindow::on_pushButton_cleaner_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    user_is_typing_second_number = false;
    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double label_number, secondnum;
    secondnum = ui->label->text().toDouble();
    QString newLabel;

    if(ui->pushButton_minus->isChecked())
    {
        label_number = firstnum - secondnum;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_plus->isChecked())
    {
        label_number = firstnum + secondnum;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        label_number = firstnum / secondnum;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        label_number = firstnum * secondnum;
        newLabel = QString::number(label_number,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
     user_is_typing_second_number = false;

}

void MainWindow::binary_operation_pressed()
{
    QPushButton *button = (QPushButton*) sender();

    firstnum = ui->label->text().toDouble();

    button->setChecked(true);

}
