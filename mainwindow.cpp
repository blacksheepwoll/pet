#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include "rule.h"
#include "pet_main.h"
#include "select_pet.h"
#include <QPalette>
#include <QFont>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //设置中文字符
    QTextCodec::setCodecForCStrings((QTextCodec::codecForName("GB2312")));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

     ui->setupUi(this);
    //设置背景图片
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap("F:/bg.jpg").scaled(// 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);                           // 给widget加上背景图

    //设置标题字体大小
    QFont ft( "Microsoft YaHei", 40, 40);
    ui->label->setFont(ft);

    //设置标题字体颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    ui->label->setPalette(pa);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
     hide();
     pet_main *pm = new pet_main(this);
     pm->show();
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
