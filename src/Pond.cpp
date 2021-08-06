#include "Pond.h"

Pond::Pond(float posX, float posY)
        : Object(posX, posY){
}

Pond::~Pond() {

}

int Pond::fishRandom() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,10);
    int p;
    p = distribution(generator);
    return p;
}