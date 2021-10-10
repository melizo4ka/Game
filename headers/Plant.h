#ifndef GAME_PLANT_H
#define GAME_PLANT_H

class Plant{
private:
    void initVariables(int seedValue, int grownValue, int daysToHarvest);

protected:
    int seedValue;
    int grownValue;
    int daysToHarvest;

public:
    Plant(int seedValue, int grownValue, int daysToHarvest);
    virtual ~Plant();

};


#endif //GAME_PLANT_H
