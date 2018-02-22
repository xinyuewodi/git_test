#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDebug>

#include "dialog_addrecord.h"

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
    void initial();

private slots:

    void on_pushButton_addRecord_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_addRecord *pDialog_add;
};

#endif // MAINWINDOW_H
