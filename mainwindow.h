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
    int getDay(int, int, int);

private slots:
    void on_btnYear_clicked();
    void on_btnQuit_clicked();
    void btnDayClicked();
    void btnInfoClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
