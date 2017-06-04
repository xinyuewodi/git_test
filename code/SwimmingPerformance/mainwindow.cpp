#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
