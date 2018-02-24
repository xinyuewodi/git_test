#ifndef DIALOG_ADDRECORD_H
#define DIALOG_ADDRECORD_H

#include <QDialog>

namespace Ui {
class Dialog_addRecord;
}

class Dialog_addRecord : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_addRecord(QWidget *parent = 0);
    ~Dialog_addRecord();

private slots:
    void on_spinBox_totalLaps_valueChanged(int arg1);

    void on_pushButton_close_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::Dialog_addRecord *ui;
};

#endif // DIALOG_ADDRECORD_H
