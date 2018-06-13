#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QGraphicsTextItem>

class Attribute: public QGraphicsTextItem{
public:
    Attribute(QGraphicsItem *parent=0);
    void set(QString str,int val);
    int setvalue(int n);
    int getvalue();

private:
    int value;
};

#endif // ATTRIBUTE_H



