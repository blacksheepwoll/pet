#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include "rule.h"
#include "pet_main.h"
#include "select_pet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //设置中文字符
    QTextCodec::setCodecForCStrings((QTextCodec::codecForName("GB2312")));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QIcon systemIcon(":/qt-logo.png");
    myTrayIcon = new QSystemTrayIcon(systemIcon,this);
    myTrayIcon->show();
    myTrayIcon->showMessage("提示","单击隐藏，双击显示主窗口");
    //myTrayIcon->setContextMenu(ui->);
    connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(activated(QSystemTrayIcon::ActivationReason)));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::activated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::Trigger:
            this->hide();
            break;
        case QSystemTrayIcon::DoubleClick:
            this->showNormal();
            break;
       default:break;
    }
}

void MainWindow::on_pushButton_clicked()
{
     game *gm = new game();
     gm->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    rule *r = new rule(this);
    r->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
