#include "notewindow.h"
#include "ui_notewindow.h"

extern int yearG;
extern int date[3];
extern QMap <QString, QString> notes;
extern QMap <QString, int> impNote;

NoteWindow::NoteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteWindow)
{
    ui->setupUi(this);
    QString s1,s2,s3,txt,s4,s5,s6;
    txt = "Заметка на ";
    if (date[0] <10){
        s1 = "0" + s1.setNum(date[0]);
    } else {
        s1.setNum(date[0]);
    }
    if (date[1] <10){
        s2 = "0" + s2.setNum(date[1]);
    } else {
        s2.setNum(date[1]);
    }
    s3.setNum(date[2]);
    ui->lblNoteDate->setText(txt+s1+"."+s2+"."+s3);
    ui->lblNoteDate->setStyleSheet("font: bold 17px black;");
    ui->lblNoteDate->setAlignment(Qt::AlignHCenter);
    s1.setNum(date[0]);
    s2.setNum(date[1]);
    ui->txtNote->insertPlainText(notes[s1+":"+s2+":"+s3]);
    ui->spinIm->setValue(impNote[s1+":"+s2+":"+s3]);
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::on_btnNoteCancel_clicked()
{
    this->close();
}

void NoteWindow::on_btnSaveNote_clicked()
{
    QString str = ui->txtNote->toPlainText();
    int val = ui->spinIm->value();
    QString s1,s2,s3;
    s1.setNum(date[0]);
    s2.setNum(date[1]);
    s3.setNum(yearG);
    notes[s1+":"+s2+":"+s3] = str;
    impNote[s1+":"+s2+":"+s3] = val;
    this->close();
}
