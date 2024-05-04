#include "widget.h"
#include "ui_widget.h"

#include <iostream>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //https://stackoverflow.com/questions/11031014/qt-widgets-setstylesheet
    ui->spinBox->setStyleSheet("QSpinBox { border: 3px solid red; border-radius: 5px; background-color: yellow; }"
                               "QSpinBox::up-arrow { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::up-arrow:hover { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::up-button { width: 80px; height: 22px; background-color: yellow; }"
                               "QSpinBox::up-button:hover { width: 80px; height: 22px; background-color: yellow; }"

                               "QSpinBox::down-arrow { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::down-arrow:hover { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::down-button { width: 80px; height: 22px; background-color: yellow; }"
                               "QSpinBox::down-button:hover { width: 80px; height: 22px; background-color: yellow; }"
                               );

    ui->spinBox_2->setStyleSheet("QSpinBox { border: 3px solid red; border-radius: 5px; background-color: yellow; }"
                               "QSpinBox::up-arrow { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::up-arrow:hover { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::up-button { width: 80px; height: 22px; background-color: yellow; }"
                               "QSpinBox::up-button:hover { width: 80px; height: 22px; background-color: yellow; }"

                               "QSpinBox::down-arrow { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::down-arrow:hover { border-left: 17px solid none;"
                               "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"
                               "QSpinBox::down-button { width: 80px; height: 22px; background-color: yellow; }"
                               "QSpinBox::down-button:hover { width: 80px; height: 22px; background-color: yellow; }"
                               );

    ui->pushButton_2->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_3->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_4->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_5->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton->setStyleSheet("QPushButton{background-color:red;}");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_spinBox_valueChanged(int arg1)
{
    int numBit1 = ui->spinBox->value();             //numBit1 = std::bitset<8>{numBit1}
    QString strBit1 = QString::number(numBit1, 2);  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber->display(strBit1);                //ui->spinBox->text()
}


void Widget::on_spinBox_2_valueChanged(int arg1)
{
    int numBit2 = ui->spinBox_2->value();             //numBit1 = std::bitset<8>{numBit1}
    QString strBit2 = QString::number(numBit2, 2);  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_2->display(strBit2);                //ui->spinBox->text()
}


void Widget::on_pushButton_2_clicked()
{
    flagBitOperation = "&";

    int numBit1 = ui->spinBox->value();
    int numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1&numBit2, 2));                //ui->spinBox->text()

    ui->pushButton->setText(QString::number(numBit1, 2) + " \&& " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1&numBit2, 2));
}


void Widget::on_pushButton_3_clicked()
{
    flagBitOperation = "|";

    int numBit1 = ui->spinBox->value();
    int numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1|numBit2, 2));                //ui->spinBox->text()

    ui->pushButton->setText(QString::number(numBit1, 2) + " \| " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1|numBit2, 2));
}


void Widget::on_pushButton_4_clicked()
{
    flagBitOperation = "^";

    int numBit1 = ui->spinBox->value();
    int numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1^numBit2, 2));                //ui->spinBox->text()

    ui->pushButton->setText(QString::number(numBit1, 2) + " \^ " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1^numBit2, 2));
}


void Widget::on_pushButton_5_clicked()
{
    flagBitOperation = "~";

    char numBit1 = ui->spinBox->value();
    char numBit2 = ui->spinBox_2->value();

    ui->lcdNumber_3->display(QString::number(~numBit1, 2));                //ui->spinBox->text()

    ui->pushButton->setText(" \~ " + QString::number(numBit1, 2) +  " = " + QString::number(~numBit1, 2) + " || " + " \~ " + QString::number(numBit2, 2) +  " = " + QString::number(~numBit2, 2));
}

