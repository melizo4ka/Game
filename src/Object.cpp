#include "Object.h"

Object::Object(float posX, float posY) {
    this->initVariables(posX, posY);
    this->sprite.setPosition(posX, posY);
}

void Object::initVariables(float posX, float posY) {
    //position top left corner
    this->posX = posX;
    this->posY = posY;
    //size of object
    this->sizeX = 64;
    this->sizeY = 64;
}