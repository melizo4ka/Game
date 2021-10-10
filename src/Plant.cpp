#include "Plant.h"

void Plant::initVariables(int seedValue, int grownValue, int daysToHarvest) {
    this->seedValue = seedValue;
    this->grownValue = grownValue;
    this->daysToHarvest = daysToHarvest;
}

Plant::Plant(int seedValue, int grownValue, int daysToHarvest){
    this->initVariables(seedValue, grownValue, daysToHarvest);
}

Plant::~Plant() {

}