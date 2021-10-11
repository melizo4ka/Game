#ifndef GAME_PLANT_H
#define GAME_PLANT_H

class Plant{
public:
    int seedValue;
    int grownValue;
    int daysToHarvest;

    Plant(int seedValue, int grownValue, int daysToHarvest);
    virtual ~Plant();

};


#endif //GAME_PLANT_H
