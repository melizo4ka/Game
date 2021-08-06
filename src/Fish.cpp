#include "Fish.h"

void Fish::initVariables(float catchingProb, int caughtValue) {
    this->catchingProb = catchingProb;
    this->caughtValue = caughtValue;
}

Fish::Fish(float catchingProb, int caughtValue)
    : Item()
{
    this->initVariables(catchingProb, caughtValue);

    this->type = ItemTypes::IT_FISH;
}

Fish::~Fish() {

}

/*Fish* Fish::clone() {
    return nullptr;
}*/