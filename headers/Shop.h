#ifndef GAME_SHOP_H
#define GAME_SHOP_H

#include "Object.h"


class Shop :
        public Object{
private:

public:
    Shop(float posX, float posY);
    virtual ~Shop() {};

};


#endif //GAME_SHOP_H
