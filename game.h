﻿#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include "attribute.h"


class game{

public:
    game();
    QGraphicsScene *scene;
    Attribute *health;
    Attribute *happiness;
    Attribute *hungry;

public slots:
    void start();


};

#endif // GAME_H
