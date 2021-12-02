#ifndef GAME_HOUSE_H
#define GAME_HOUSE_H

#include "Object.h"


class Object;

class House :
        public Object{
private:

public:
    House(float posX, float posY);
    virtual ~House() {};

};


#endif //GAME_HOUSE_H
