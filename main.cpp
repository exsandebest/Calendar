#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QStyleFactory>
using namespace Qt;


int getDay(int day, int mon, int year) {
    int a = (14-mon)/12;
    int y = year-a;
    int m = mon+12*a-2;
    int r = ((7000+(day+y+(y/4)-(y/100) + (y/400) +(31*m)/12))%7);
    return r==0?7:r;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


