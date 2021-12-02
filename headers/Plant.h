#ifndef GAME_PLANT_H
#define GAME_PLANT_H

class Plant{
public:
    int seedValue;
    int grownValue;

    Plant(int seedValue, int grownValue);
    virtual ~Plant() {};

};


#endif //GAME_PLANT_H
