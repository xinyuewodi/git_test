#include "dialog_addrecord.h"
#include "ui_dialog_addrecord.h"

#include <QDebug>

Dialog_addRecord::Dialog_addRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_addRecord)
{
    ui->setupUi(this);
}

Dialog_addRecord::~Dialog_addRecord()
{
    delete ui;
}

