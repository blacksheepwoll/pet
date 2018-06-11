#include "data.h"

QString Pet::getname(){
    return name;
}

QString Pet::gettype(){
    return type;
}

int Pet::gethealth(){
    return health;
}

int Pet::gethappiness(){
    return happiness;
}

void Pet::set(QString iname){
    name=iname;
    health=80;
    happiness=80;
}
