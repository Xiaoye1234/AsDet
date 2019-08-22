#include "ui_dialogaboutthisxcan.h"
#include "AboutXcan/dialogaboutthisxcan.h"
#include "mainwindow.h"
#include <qdebug.h>

DialogAboutThisXcan::DialogAboutThisXcan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAboutThisXcan)
{
    ui->setupUi(this);    
//    ui->lineEdit_UsbSerial->setText(GetUsbCanSerial());
}

DialogAboutThisXcan::~DialogAboutThisXcan()
{
    delete ui;
}
void DialogAboutThisXcan::closeEvent(QCloseEvent *event)
{
    //|窗口关闭之前需要的操作~
    MainWindow::isOpen_dialogAboutThisXcan_ui = false;
}
QString DialogAboutThisXcan::GetUsbCanSerial(void)
{
    QString serial;
//    USBCAN::GetDeviceSerial(&serial);
    qDebug()<<"serial"<<serial;
    return serial;
}
