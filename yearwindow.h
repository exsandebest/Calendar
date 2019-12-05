#ifndef YEARWINDOW_H
#define YEARWINDOW_H

#include <QDialog>

namespace Ui {
class YearWindow;
}

class YearWindow : public QDialog
{
    Q_OBJECT

public:
    explicit YearWindow(QWidget *parent = 0);
    ~YearWindow();

private slots:
    void on_btnGetYear_clicked();

    void on_btbCancelYear_clicked();

private:
    Ui::YearWindow *ui;
};

#endif // YEARWINDOW_H
