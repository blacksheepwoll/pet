#include "attribute.h"
#include <QFont>

Attribute::Attribute(QGraphicsItem *parent): QGraphicsTextItem(parent){

    value = 80;
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",10));


}

void Attribute::set(QString str, int val){
    value = val;
    setPlainText(str+QString::number(value));
}

int Attribute::setvalue(int n) {
    value = value + n ;
    return value;
}

int Attribute::getvalue() {
    return value;
}

