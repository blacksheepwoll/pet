#include "pet_main.h"
#include "ui_pet_main.h"
#include "mainwindow.h"
#include <QLabel>
#include <QMovie>
#include <QDir>
#include <QMessageBox>

pet_main::pet_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pet_main)
{
    w = parent;

    QIcon systemIcon(":/qt-logo.png");
    myTrayIcon = new QSystemTrayIcon(systemIcon,this);
    myTrayIcon->show();
    myTrayIcon->showMessage("提示","单击隐藏，双击显示主窗口");
    //myTrayIcon->setContextMenu(ui->);
    connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(activated(QSystemTrayIcon::ActivationReason)));

    int flag=1;
    ui->setupUi(this);

   //设置背景图片
   this->setAutoFillBackground(true);
   QPalette palette = this->palette();
   palette.setBrush(QPalette::Window,
           QBrush(QPixmap(":/bg.jpg").scaled(// 缩放背景图.
               this->size(),
               Qt::IgnoreAspectRatio,
               Qt::SmoothTransformation)));             // 使用平滑的缩放方式
   this->setPalette(palette);                           // 给widget加上背景图

    if (flag) {
        happiness = 80;
        health = 80;
        hungry = 50;
    }
    update_lineexit();

    mgif_happy = new QMovie("./res/happy.gif");
    mgif_play = new QMovie("./res/play.gif");
    mgif_work = new QMovie("./res/work.gif");
    mgif_eat = new QMovie("./res/sleep.gif");
    mgif_rest = new QMovie("./res/travel.gif");
    mgif_sport1 = new QMovie("./res/sport1.gif");
    mgif_sport3 = new QMovie("./res/sport3.gif");
    mgif_angry = new QMovie("./res/angry.gif");

    ui->label_gif->setMovie(mgif_happy);   
    mgif_happy->start();
    state = 1;
    meal = 0;
}

pet_main::~pet_main()
{
    delete ui;
}
void pet_main::activated(QSystemTrayIcon::ActivationReason reason)
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

void pet_main::update_lineexit()
{
    ui->lineEdit->setText(QString::number(happiness));
    ui->lineEdit_2->setText(QString::number(health));
    ui->lineEdit_3->setText(QString::number(hungry));
}

void pet_main::on_button_exit_clicked()
{
    close();
}

void pet_main::on_button_return_clicked()
{
    close();
    w->show();
}

int  pet_main::judge()
{
    if ( happiness < 50 && state == 1 )
    {
        QMessageBox::information(this,"状态","今天真不开心");
        ui->label_gif->setMovie(mgif_angry);
        mgif_angry->start();
        state = 2;
    }
    else if ( happiness >= 50 && state == 2 )
    {
        QMessageBox::information(this,"状态","又是开心的一天");
        ui->label_gif->setMovie(mgif_happy);
        mgif_happy->start();
        state = 1;
    }
    return 1;
}

int pet_main::set(int a, int b, int c)
{
    int x,y,z;
    x = happiness + a;
    y = health + b;
    z = hungry + c;
    if ( x >= 100 || y >= 100 || z >= 100 )
    {
        QMessageBox::information(this,"消息","主人，做一下其它事情吧");
        return 1;
    }
    else
    {
        happiness = x;
        health = y;
        hungry = z;
        return 0;
    }
}

void pet_main::changegif(QMovie *m)
{
    update_lineexit();
    ui->label_gif->setMovie(m);
    m->start();
    judge();
};

void pet_main::on_button_play_clicked()
{ 
    if ( set(10,-3,-5) ) return;
    changegif(mgif_play);
}

void pet_main::on_button_work_clicked()
{
    if (  set(-15,-10,-4) ) return;
    changegif(mgif_work);
}

void pet_main::on_button_eat_clicked()
{
    if (  set(4,8,20) ) return;
    if ( meal >= 3 )
    {
        QMessageBox::information(this,"消息","今天已经吃过3顿饭了，再吃要长胖了");
        return;
    }
    changegif(mgif_eat);
    meal++;
    QString str("今天已经吃了");
    str.append(QString::number(meal,10));
    str.append("顿饭了");
    QMessageBox::information(this,"消息",str);
}

void pet_main::on_button_sport_clicked()
{
    if ( set(3,12,-10) ) return;
    changegif(mgif_sport1);
}

void pet_main::on_button_sleep_clicked()
{
    if ( set(2,0,-2) ) return;
    changegif(mgif_rest);
}

void pet_main::on_button_musci_clicked()
{
    if ( set(8,5,-3) ) return;
    changegif(mgif_sport3);
}
