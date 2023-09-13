#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            EchoInterface* echoInterface = qobject_cast<EchoInterface *>(plugin);
//            QVariant *varData=new QVariant();
//            varData->setValue(echoInterface);
            ui->comboBox->addItem(echoInterface->Name());
            echoList.append(echoInterface);
        }
    }
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_btnSend_clicked()
{
    if(ui->comboBox->currentIndex()>=0)
    {
        QString rec=echoList.at(ui->comboBox->currentIndex())->echo(ui->lineSend->text());
        ui->lineRec->setText(rec);
    }
}
