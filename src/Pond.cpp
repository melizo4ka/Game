#include "Pond.h"

Pond::Pond(float posX, float posY)
        : Object(posX, posY){
}

int Pond::fishRandom() {
    int p = rand() % 8;  // in the range 0 to 7
    return p;
}