#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>

namespace Ui {
class NoteWindow;
}

class NoteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = 0);
    ~NoteWindow();

private slots:
    void on_btnNoteCancel_clicked();

    void on_btnSaveNote_clicked();

private:
    Ui::NoteWindow *ui;
};

#endif // NOTEWINDOW_H
