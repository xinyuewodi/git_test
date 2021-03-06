#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDebug>

#include "dialog_addrecord.h"
#include "databasemanager.h"
#include "swimrecordtablemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool initialDataBase();
    void initialValues();

private slots:

    void on_pushButton_addRecord_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_addRecord *pDialog_add;
    DataBaseManager *_pDataBase;
    SwimRecordTableManager _swimRecordManager;
};

#endif // MAINWINDOW_H
