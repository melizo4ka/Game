#include "Plant.h"

void Plant::initVariables(int seedValue, int grownValue, int daysToHarvest) {
    this->seedValue = seedValue;
    this->grownValue = grownValue;
    this->daysToHarvest = daysToHarvest;
}

Plant::Plant(int seedValue, int grownValue, int daysToHarvest)
    : Item()
{
    this->initVariables(seedValue, grownValue, daysToHarvest);

    this->type = ItemTypes::IT_PLANT;

}

Plant::~Plant() {

}

/*Plant* Plant::clone() {
    return nullptr;
}*/

void Plant::update() {

}

void Plant::render() {

}