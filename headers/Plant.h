#ifndef GAME_PLANT_H
#define GAME_PLANT_H

#include "Item.h"

class Item;

class Plant :
        public Item{
private:
    void initVariables(int seedValue, int grownValue, int daysToHarvest);

protected:
    int seedValue;
    int grownValue;
    int daysToHarvest;

public:
    Plant(int seedValue, int grownValue, int daysToHarvest);
    virtual ~Plant();

    //virtual Plant* clone() = 0;

    virtual void update();
    virtual void render();
};


#endif //GAME_PLANT_H
