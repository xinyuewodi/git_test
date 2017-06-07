#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_actionChinese_triggered();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initial()
{
    pDialog_add = nullptr;
}

void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_addRecord_clicked()
{
    pDialog_add = new Dialog_addRecord;
    pDialog_add->setAttribute(Qt::WA_DeleteOnClose);
    pDialog_add->exec();
}

void MainWindow::on_actionChinese_triggered()
{
    if(true == translator.load("swimmingperformance_cn.qm"))
    {
        qDebug() << "MainWindow,install cn translator success";
        qApp->installTranslator(&translator);
    }
}

void MainWindow::on_actionEnglish_triggered()
{
    if(true == translator.load("swimmingperformance_en.qm"))
    {
        qDebug() << "MainWindow,install en translator success";
        qApp->installTranslator(&translator);
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        qDebug() << "MainWindow::LanguageChange";
        ui->retranslateUi(this);
    }
    else
    {
        QWidget::changeEvent(event);
    }
}
