#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int flag=0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if ( !flag ) {
        //原来无游戏记录

    }
    else {
        //有游戏记录

    }
    return a.exec();
}
