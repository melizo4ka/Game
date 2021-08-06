#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Player.h"


class Object {
private:
    float posX;
    float posY;
    float sizeX;
    float sizeY;

    void initVariables(float posX, float posY);


protected:
    Sprite sprite;

public:
    Object(float posX, float posY);
    virtual ~Object();
};


#endif //GAME_OBJECT_H
