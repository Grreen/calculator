#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "st.h"
#include <QValidator>
#include <QRegExp>
#include <QMessageBox>
#include <QColorDialog>
#include <QPalette>

using namespace std;


extern ST first_class;
extern ST second_class;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(50);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), this));
    ui->lineEdit_2->setMaxLength(50);
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), this));

    //ui->pushButton->setStyleSheet("QPushButton{background:#FF0063;}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString stroka;

    if ((ui->lineEdit->text()=="")&&(ui->lineEdit_2->text()==""))
        QMessageBox::warning(this, "Ошибка ввода!", "Не введены значения в первое и второе поле!");
    else if (ui->lineEdit->text()=="")
        QMessageBox::warning(this, "Ошибка ввода!", "Не введено значение в первое поле!");
    else if (ui->lineEdit_2->text()=="")
        QMessageBox::warning(this, "Ошибка ввода!", "Не введено значение во второе поле!");
    else if (ui->comboBox->currentText()=="Сложение")
    {
        first_class.stroka=ui->lineEdit->text();
        second_class.stroka=ui->lineEdit_2->text();
        if(ui->button_sign_1->text()==ui->button_sign_2->text())
        {
            ui->lineEdit_3->setText(first_class+second_class);
            if(ui->button_sign_1->text()=="-")
                ui->lineEdit_3->setText("-"+ui->lineEdit_3->text());
        }
        else if(ui->button_sign_1->text()=="-")
           ui->lineEdit_3->setText(second_class-first_class);
        else if(ui->button_sign_2->text()=="-")
           ui->lineEdit_3->setText(first_class-second_class);
    }
    else if (ui->comboBox->currentText()=="Вычитание")
    {
        first_class.stroka=ui->lineEdit->text();
        second_class.stroka=ui->lineEdit_2->text();
        if((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="+"))
            ui->lineEdit_3->setText(first_class-second_class);
        else if((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="-"))
            ui->lineEdit_3->setText(first_class+second_class);
        else if((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="-"))
            ui->lineEdit_3->setText(second_class-first_class);
        else if((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="+"))
            ui->lineEdit_3->setText("-"+(first_class+second_class));
    }
    else if (ui->comboBox->currentText()=="Умножение")
    {
        first_class.stroka=ui->lineEdit->text();
        second_class.stroka=ui->lineEdit_2->text();
        if (((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="+"))||((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="-")))
            ui->lineEdit_3->setText("-"+(first_class*second_class));
        else if(ui->button_sign_1->text()==ui->button_sign_2->text())
            ui->lineEdit_3->setText(first_class*second_class);
    }
    else if(ui->comboBox->currentText()=="Деление")
    {
        ui->lineEdit_3->setText("Пока не додумался как это сделать(((");
    }
    else if(ui->comboBox->currentText()=="Сравнение")//учесть знаки
    {
        int res=first_class.comparison(ui->lineEdit->text(),ui->lineEdit_2->text());
        if(res==0)
        {
            if (((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="-"))||((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="+")))
            {
                if(ui->button_sign_1->text()=="-")
                    ui->lineEdit_3->setText("Второе число больше первого");
                else if(ui->button_sign_1->text()=="+")
                    ui->lineEdit_3->setText("Первое число больше второго");
            }
            else
                ui->lineEdit_3->setText("Числа равны");
        }
        else if(res==1)
        {
            if (((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="-"))||((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="+")))
            {
                if(ui->button_sign_1->text()=="-")
                    ui->lineEdit_3->setText("Второе число больше первого");
                else if(ui->button_sign_1->text()=="+")
                    ui->lineEdit_3->setText("Первое число больше второго");
            }
            else if(ui->button_sign_1->text()=="+")
                ui->lineEdit_3->setText("Первое число больше второго");
            else if(ui->button_sign_1->text()=="-")
                ui->lineEdit_3->setText("Второе число больше первого");
        }
        else if(res==2)
        {
            if (((ui->button_sign_1->text()=="+")&&(ui->button_sign_2->text()=="-"))||((ui->button_sign_1->text()=="-")&&(ui->button_sign_2->text()=="+")))
            {
                if(ui->button_sign_2->text()=="-")
                    ui->lineEdit_3->setText("Первое число больше второго");
                else if(ui->button_sign_2->text()=="+")
                    ui->lineEdit_3->setText("Второе число больше первого");
            }
            else if(ui->button_sign_2->text()=="+")
                ui->lineEdit_3->setText("Второе число больше первого");
            else if(ui->button_sign_2->text()=="-")
                ui->lineEdit_3->setText("Первое число больше второго");
        }
    }
}
//как то узнать код из color?

void MainWindow::on_action_triggered()
{
    QColor color = QColorDialog::getColor() ;


}

void MainWindow::on_button_sign_1_clicked()
{
    if(ui->button_sign_1->text()=="+")
         ui->button_sign_1->setText("-");
    else
        ui->button_sign_1->setText("+");
}

void MainWindow::on_button_sign_2_clicked()
{
    if(ui->button_sign_2->text()=="+")
         ui->button_sign_2->setText("-");
    else
        ui->button_sign_2->setText("+");
}
