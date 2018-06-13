#include "game.h"

game::game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setFixedSize(800,600);
    health = new Attribute();
    health->set("健康值:",80);
    scene->addItem(health);

    happiness = new Attribute();
    happiness->set("快乐值:",80);
    happiness->setPos(happiness->x(),happiness->y()+35);
    scene->addItem(happiness);

    hungry = new Attribute();
    hungry->set("饥饿值:",50);
    hungry->setPos(hungry->x(),hungry->y()+70);
    scene->addItem(hungry);


    //show();
}

void game::start(){
    scene->clear();
}
