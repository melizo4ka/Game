#ifndef GAME_FISH_H
#define GAME_FISH_H

#include "Item.h"

class Item;

class Fish :
        public Item{
private:
    void initVariables(float catchingProb, int caughtValue);

protected:

public:
    float catchingProb;
    int caughtValue;

    Fish(float catchingProb, int caughtValue);
    virtual ~Fish();

    //virtual Fish* clone() = 0;


};


#endif //GAME_FISH_H
