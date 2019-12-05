#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "yearwindow.h"
#include "notewindow.h"
#include <QDebug>
#include <QtWidgets>
#include <QPalette>
#include <QMap>
#include <QPixmap>
extern int yearG;
int date[3];
extern int flagG;
QMap <QString, int> impNote;
QMap <QString, QString> notes;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_btnYear_clicked();
    QObject::connect(ui->btnInfo,SIGNAL(clicked()), this,SLOT(btnInfoClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow :: btnDayClicked(){
    QObject* btn = sender();
    qDebug() << btn->property("id").toString();
    QString s = btn->property("id").toString();
    QStringList list = s.split(":");
    qDebug() << list;
    for (int i = 0; i <3 ;++i){
        date[i] = list[i].toInt();
    }
    NoteWindow nwin;
    nwin.setModal(true);
    nwin.exec();

    QString s1,s2,s3;
    s1.setNum(date[0]);
    s2.setNum(date[1]);
    s3.setNum(yearG);
    if(notes[s1+":"+s2+":"+s3].replace(QRegularExpression("\n"),"") != ""){
        QString st = "";
        for (int i = 0; i<impNote[s1+":"+s2+":"+s3]; ++i){
            st += "•";
        }
        btn->setProperty("text",st+s1+st);
    } else {
        btn->setProperty("text",s1);
    }




}
void MainWindow :: btnInfoClicked(){
    QString s;
    s.setNum(yearG);
QDesktopServices::openUrl(QUrl("https://ru.wikipedia.org/wiki/"+s+"_год"));
}

int getWeekDay(int day, int mon, int year) {
    int a = (14-mon)/12;
    int y = year-a;
    int m = mon+12*a-2;
    int r = ((7000+(day+y+(y/4)-(y/100) + (y/400) +(31*m)/12))%7);
    return r==0?7:r;
}

bool checkBis(){
    bool bis = false;
    if (yearG%400 == 0){
        bis = true;
    } else if (yearG%100 == 0){
        bis = false;
    } else if (yearG%4 == 0){
        bis = true;
    }
    qDebug() << bis;
    return bis;

}

void MainWindow::on_btnYear_clicked()
{

    YearWindow ywin;
    ywin.setModal(true);
    ywin.exec();
    qDebug() << yearG;
    if (flagG == 0){
        on_btnYear_clicked();
    } else if (flagG == 1){

    } else {
        QString animalLbl[12] = {"Обезьяны", "Петуха", "Собаки", "Свиньи", "Крысы", "Быка", "Тигра", "Кролика", "Дракона" , "Змеи", "Лошади", "Овцы"};
        int mon[12] = {31, 28,31,30,31,30,31,31,30,31,30,31};
        QString monlbl[12] = {"Январь", "Ферваль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
       bool bis = checkBis();
       QString lbltxt;
       lbltxt.setNum(yearG);
       ui->btnInfo->setFlat(true);
       ui->btnInfo->setStyleSheet("font:bold 15px; color: rgb(219, 87, 255);");
       ui->btnInfo->setText("Узнать больше про "+lbltxt+" год");
       QString str;
       str.setNum(yearG%12);
       QPixmap pix(":/src/img/"+str+".jpg");
       ui->lblImg->setPixmap(pix);
       ui->lblAnimal->setText("Год "+animalLbl[yearG%12]);
       ui->lblAnimal->setAlignment(Qt::AlignCenter);
       ui->lblAnimal->setStyleSheet("color:rgb(54, 207, 84)");
       if(bis){
       ui->lblBis->setText("Високосный");
       } else {
       ui->lblBis->setText("Невисокосный");
       }
       ui->lblBis->setStyleSheet("color:rgb(252, 8, 69)");
       ui->lblBis->setAlignment(Qt::AlignCenter);
       lbltxt+= " год";
       ui->lblYear->setText(lbltxt);
       ui->lblYear->setStyleSheet("color:rgb(255, 0, 81)");

      QLayoutItem* item;
      while ((item = ui->mainLay->takeAt(0)) != NULL){
      delete item->widget();
          delete item;
      }

      for (int i =0 ; i<=36; i=i+9){
          for(int j = 1; j<=19; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Пн</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 2; j<=20; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Вт</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 3; j<=21; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Ср</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 4; j<=22; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Чт</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 5; j<=23; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Пт</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 6; j<=24; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Сб</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
          }
          for(int j = 7; j<=25; j = j+9){
              QLabel *lbl = new QLabel("<span style='font: bold 14px black;'>Вс</span>");
            ui->mainLay->addWidget(lbl,j,i,1,1);
            QLabel *lbl1 = new QLabel("");
          ui->mainLay->addWidget(lbl1,j+1,i,1,1);
          }

      }

          int t = 0;
          for (int i = 0; i<=2; ++i){
              for (int j = 0; j <= 3; ++j){
                  QString s = "<span style=' font: bold 13px rgb(30,144,255); color:rgb(30,144,255);'>"+monlbl[t]+"</span>";
                  QLabel *lbl = new QLabel(s);
                  ui->mainLay->addWidget(lbl, i*9,j*9);
                  ++t;
              }
          }

    int holidays = 0;
       if(true){
           int t = 5;
          int i = 1;
            int weekDay;
               for (int d = 0; d <= 2; ++d){
               for (int g = 0; g <= 3; ++g){
               int k = 1;
               for(int j = 1; j<=6; ++j){
                  while(true){
                      weekDay = getWeekDay(k,i,yearG);
                      QString s;
                      s.setNum(k);
                      QPushButton *btn = new QPushButton(s);
                        btn->setFlat(true);
                        if (weekDay == 7 || weekDay == 6 ){
                           btn->setStyleSheet("color:#FF4500; font:bold;");
                        }
                        if (k == qrand()%30 && weekDay != 7 && weekDay !=6){
                            btn->setStyleSheet("color:#FF4500; font:bold");
                            holidays++;
                        }
                        QString s1,s2,s3;
                        s1.setNum(k);
                        s2.setNum(i);
                        s3.setNum(yearG);
                        btn->setProperty("id",s1+":"+s2+":"+s3);
                        if (notes[s1+":"+s2+":"+s3].replace(QRegularExpression("\n"), "") != ""){
                            QString st = "";
                            for (int i = 0; i<impNote[s1+":"+s2+":"+s3]; ++i){
                                st += "•";
                            }
                            btn->setText(st+s1+st);
                        }
                        QObject :: connect(btn,SIGNAL(clicked()),this,SLOT(btnDayClicked()));
                      ui->mainLay->addWidget(btn, weekDay+d*9,j +g*9);
                      if (weekDay == 7){
                          ++k;
                          break;
                      }
                      if (d == 0 && g == 1 && k>mon[i-1]){
                          t = j;
                      }
                      ++k;
                        if(k >mon[i-1]) break;
                  }
                    if(k >mon[i-1]) break;
               }
               ++i;
               }
               }


               if (bis){
                   qDebug() << t;
                   QString s;
                   s.setNum(29);
                   QPushButton *btn = new QPushButton(s);
                     btn->setFlat(true);
                     if (getWeekDay(29,2,yearG) == 7 || getWeekDay(29,2,yearG) == 6){
                         btn->setStyleSheet("color:#FF4500; font:bold;");
                     }
                     QString s1,s2,s3,s4,s5,s6;
                     s1.setNum(29);
                     s2.setNum(2);
                     s3.setNum(yearG);
                     btn->setProperty("id",s1+":"+s2+":"+s3);
                     if (notes[s1+":"+s2+":"+s3].replace(QRegularExpression("\n"), "") != ""){
                         QString st = "";
                         for (int i = 0; i<impNote[s1+":"+s2+":"+s3]; ++i){
                             st += "•";
                         }
                         btn->setText(st+s4+st);
                     }
                     QObject :: connect(btn,SIGNAL(clicked()),this,SLOT(btnDayClicked()));
                     ui->mainLay->addWidget(btn, getWeekDay(29,2,yearG),t+9);
               }
               QString s;
               s.setNum(holidays);
               ui->lblHol->setText("Кол-во праздников: "+s);
               ui->lblHol->setStyleSheet("color:rgb(255, 153, 0)");
               ui->lblHol->setAlignment(Qt::AlignCenter);

       }
    }

}



void MainWindow::on_btnQuit_clicked()
{

    QMessageBox::StandardButton ans = QMessageBox::question(this, "Выход","Вы действительно хотите выйти из приложения?", QMessageBox::Yes|QMessageBox::No);
    if (ans ==QMessageBox:: Yes){
        QApplication::quit();
    } else {

    }
}


