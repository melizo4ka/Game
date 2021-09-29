#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "Player.h"

enum ItemTypes {IT_DEFAULT = 0, IT_FISH, IT_PLANT}; //class enum senza short unsigned

class Item
{

    //cost
private:
    void initVariables();

protected:
    short unsigned type;

public:
    Item();
    virtual ~Item();

    //virtual Item* clone() = 0;

};

#endif //GAME_ITEM_H
