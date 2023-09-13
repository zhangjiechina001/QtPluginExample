#pragma execution_character_set("utf-8")
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "echointerface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
    QList<EchoInterface*> echoList;
};

#endif // MAINWINDOW_H
