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
    //1.提取输入数据
    SwimRecord record;
    record.totalLap = ui->spinBox_totalLaps->text().toInt();        //总圈数
    record.totalTime = ui->timeEdit_totalTime->time();              //总时间
    record.avgTime = ui->timeEdit_avgTime->time();                  //每圈平均时间
    record.FastestLapNum = ui->spinBox_fastestLap->text();          //最快圈号
    record.FLapTimeCost = ui->timeEdit_FTimeCost->time();           //最快圈时间
    record.SLowestLapNum = ui->spinBox_slowestLap->text();          //最慢圈号
    record.SLapTimeCost = ui->timeEdit_STimeCost->time();           //最慢圈时间

    record.date = QDate::currentDate();                             //今天日期

#ifdef DEBUG_DIALOG_ADDRECORD
    qDebug() << "totalLap:" << record.totalLap;
    qDebug() << "totalTime:" << record.totalTime;
    qDebug() << "avgTime:" << record.avgTime;
    qDebug() << "FastestLapNum:" << record.FastestLapNum;
    qDebug() << "FLapTimeCost:" << record.FLapTimeCost;
    qDebug() << "SLowestLapNum:" << record.SLowestLapNum;
    qDebug() << "SLapTimeCost:" << record.SLapTimeCost;
    qDebug() << "date:" << record.date;
#endif

    //2.提取详细数据
    DetailSwimRecord tmpRecord;                                     //单个记录
    QList<DetailSwimRecord> records;                                //最终提取到的数据
    QWidget *widget;                                                //单元格widget
    QTime time;                                                     //单元格widget的值
    QString lapNum;                                                 //圈号

    int rowCount = ui->tableWidget_dataInput->rowCount();
    for(int i=0; i < rowCount; ++i)
    {
        //获取圈号
        lapNum = ui->tableWidget_dataInput->item(i, 0)->data(Qt::DisplayRole).toString();
        tmpRecord.lapNum = lapNum;

        //获取单圈耗时
        widget = ui->tableWidget_dataInput->cellWidget(i, 1);
        time = dynamic_cast<QTimeEdit *>(widget)->time();
        tmpRecord.record = time;

#ifdef DEBUG_DIALOG_ADDRECORD
        qDebug() << "lapNum:" << tmpRecord.lapNum << " " << "timeCost:" << tmpRecord.record;
#endif

        records << tmpRecord;                                       //最终提取到的数据
    }

    //3.写入数据库

    //4.弹框提示完成
    QMessageBox msg;
    msg.setWindowTitle("输入");
    msg.setText("输入完成");
    msg.exec();

    this->close();
}

//void Dialog_addRecord::on_radioButton_simplfunc_clicked()
//{
//    ui->label_fastestLap->setVisible(false);
//    ui->label_FTimeCost->setVisible(false);
//    ui->label_slowestLap->setVisible(false);
//    ui->label_STimeCost->setVisible(false);

//    ui->spinBox_fastestLap->setVisible(false);
//    ui->spinBox_slowestLap->setVisible(false);
//    ui->timeEdit_FTimeCost->setVisible(false);
//    ui->timeEdit_STimeCost->setVisible(false);

//    ui->groupBox_data->setVisible(false);
//    ui->tableWidget_dataInput->setVisible(false);
//}
