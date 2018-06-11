#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <QString>
using namespace std;

class Pet {

    private:
        QString name;
        QString type;
        int health;
        int happiness;
        int mealtimes;
    public:
        QString getname();
        QString gettype();
        int  gethealth();
        int  gethappiness();
        void  set(QString name);
};

#endif // DATA_H
