#include "widget.h"
#include "ui_widget.h"

#include <iostream>
#include <string>

#include <QBitArray>


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

    ui->pushButton_22->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_33->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_44->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_66->setStyleSheet("QPushButton:hover{background-color:red;}");

    ui->pushButton_2->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_3->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_4->setStyleSheet("QPushButton:hover{background-color:red;}");
    ui->pushButton_5->setStyleSheet("QPushButton:hover{background-color:red;}");

    ui->pushButton->setStyleSheet("QPushButton{background-color:red;}");

    ui->spinBox->setToolTip("set Number X");
    ui->spinBox_2->setToolTip("set Number Y");

    ui->lcdNumber->setToolTip("view Number X");
    ui->lcdNumber_2->setToolTip("view Number Y");
    ui->lcdNumber_3->setToolTip("view RESULT bit operation");

    ui->pushButton_2->setToolTip("bit operation X & Y");
    ui->pushButton_3->setToolTip("bit operation X | Y");
    ui->pushButton_4->setToolTip("bit operation X ^ Y");
    ui->pushButton_5->setToolTip("bit operation ~X");

    ui->pushButton_22->setToolTip("bit operation X >> 1");
    ui->pushButton_33->setToolTip("bit operation X >> 2");
    ui->pushButton_44->setToolTip("bit operation X << 1");
    ui->pushButton_66->setToolTip("bit operation X << 2");

    ui->pushButton->setToolTip("RESULT bit operation");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spinBox_valueChanged(int arg1)
{
    quint8 numBit1 = ui->spinBox->value();             //numBit1 = std::bitset<8>{numBit1}
    QString strBit1 = QString::number(numBit1, 2);  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber->display(strBit1);                //ui->spinBox->text()
}

void Widget::on_spinBox_2_valueChanged(int arg1)
{
    quint8 numBit2 = ui->spinBox_2->value();
    QString strBit2 = QString::number(numBit2, 2);
    ui->lcdNumber_2->display(strBit2);
}

void Widget::on_pushButton_2_clicked()
{
    flagBitOperation = "&";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1&numBit2, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) + " \&& " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1&numBit2, 2));
}

void Widget::on_pushButton_3_clicked()
{
    flagBitOperation = "|";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1|numBit2, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) + " \| " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1|numBit2, 2));
}

void Widget::on_pushButton_4_clicked()
{
    flagBitOperation = "^";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();
    //QString strBit1 = ;  //strBit1.toStdString(std::bitset<8>{11});
    ui->lcdNumber_3->display(QString::number(numBit1^numBit2, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) + " \^ " + QString::number(numBit2, 2) + " = "
                            + QString::number(numBit1^numBit2, 2));
}

void Widget::on_pushButton_5_clicked()
{
    flagBitOperation = "~";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();

    QBitArray a(9); // https://doc.qt.io/qt-6/qbitarray.html#operator-5e
    QBitArray b;

    QString myString=QString::number(numBit1, 2);
    for(int i = 0; i < myString.length(); i++)
    {
        if (myString.at(i) == '1')
            a[i] = 1;
        else
            a[i] = 0;
    }

    b = ~a;
    QString strnumBit1="";
    QString srtnumBit1_NOT="";

    for(int i = 0; i < myString.length(); i++) //https://forum.qt.io/topic/78375/coversion-of-qstring-to-char-array/3
    {
        strnumBit1 = strnumBit1 + QString::number((int)a[i]);
        srtnumBit1_NOT = srtnumBit1_NOT + QString::number((int)b[i]) ;
    }

    ui->pushButton->setText(" \~ " + QString::number(numBit1, 2) +  " = " + srtnumBit1_NOT);
    ui->lcdNumber_3->display(srtnumBit1_NOT);
}

void Widget::on_pushButton_22_clicked()
{
    flagBitOperation = ">> +1";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();

    ui->lcdNumber_3->display(QString::number(numBit1>>1, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) +  " >> 1 = " + QString::number(numBit1>>1, 2));
}

void Widget::on_pushButton_33_clicked()
{
    flagBitOperation = ">> +2";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();

    ui->lcdNumber_3->display(QString::number(numBit1>>2, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) +  " >> 2 = " + QString::number(numBit1>>2, 2));
}

void Widget::on_pushButton_44_clicked()
{
    flagBitOperation = "<< +1";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();

    ui->lcdNumber_3->display(QString::number(numBit1<<1, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) +  " << 1 = " + QString::number(numBit1<<1, 2));
}

void Widget::on_pushButton_66_clicked()
{
    flagBitOperation = "<< +2";

    quint8 numBit1 = ui->spinBox->value();
    quint8 numBit2 = ui->spinBox_2->value();

    ui->lcdNumber_3->display(QString::number(numBit1<<2, 2));

    ui->pushButton->setText(QString::number(numBit1, 2) +  " << 2 = " + QString::number(numBit1<<2, 2));
}

