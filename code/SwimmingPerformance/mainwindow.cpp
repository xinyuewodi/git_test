#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化数据库
    _pDataBase = DataBaseManager::getInstance();
    _pDataBase->createConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
    //关闭数据库
    _pDataBase->closeConnection();
}

void MainWindow::initial()
{
    pDialog_add = nullptr;
}

void MainWindow::on_pushButton_addRecord_clicked()
{
    pDialog_add = new Dialog_addRecord;
    pDialog_add->setAttribute(Qt::WA_DeleteOnClose);
    pDialog_add->exec();
}
