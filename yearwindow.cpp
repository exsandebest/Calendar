#include "yearwindow.h"
#include "ui_yearwindow.h"
#include <QMessageBox>
#include <QString>
#include <bits/stdc++.h>
#include <string>
#include <QDebug>
#include "mainwindow.h"
int yearG;
int flagG;
YearWindow::YearWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YearWindow)
{
    ui->setupUi(this);
}

YearWindow::~YearWindow()
{
    delete ui;
}
bool checkYear(QString str){
    bool fl;
    int y = str.toInt(&fl);
    if (!fl){
        return false;
    } else {
        if (y <= 0){
            return false;
        } else {
            return true;
        }
    }

}


void YearWindow::on_btnGetYear_clicked()
{
    hide();
    QString year = ui->inputYear->text();
    if (checkYear(year)){
        yearG = year.toInt();
        flagG = 127;
    } else {
        QMessageBox ::warning(this, "Некорректно","Некорректный год");
       flagG = 0;
    }


}



void YearWindow::on_btbCancelYear_clicked()
{
 flagG = 1;
    hide();

}
