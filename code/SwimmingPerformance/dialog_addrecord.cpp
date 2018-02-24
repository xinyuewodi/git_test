#include "dialog_addrecord.h"
#include "ui_dialog_addrecord.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimeEdit>

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


void Dialog_addRecord::on_spinBox_totalLaps_valueChanged(int arg1)
{
    //输入条件判断
    if(0 >= arg1)
    {
        QMessageBox::information(this, "圈数", "圈数不能为0或负数");
        return;
    }

    //清除表中原有内容
    ui->tableWidget_dataInput->clearContents();

    //设置行数
    ui->tableWidget_dataInput->setRowCount(arg1);

    //设置圈号
    for(int row = 0; row < arg1; ++row)
    {
        ui->tableWidget_dataInput->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
        ui->tableWidget_dataInput->item(row, 0)->setFlags(Qt::NoItemFlags);                             //圈号不可编辑
    }

    //设置cell widget
    for(int row = 0; row < arg1; ++row)
    {
        ui->tableWidget_dataInput->setCellWidget(row, 1, new QTimeEdit());
    }
}

void Dialog_addRecord::on_pushButton_close_clicked()
{
    this->close();
}

void Dialog_addRecord::on_pushButton_confirm_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("输入");
    msg.setText("输入完成");
    msg.exec();

    this->close();
}
