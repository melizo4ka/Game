#include "Fish.h"

void Fish::initVariables(int caughtValue) {
    this->caughtValue = caughtValue;
}

Fish::Fish(int caughtValue){
    this->initVariables(caughtValue);
}

Fish::~Fish() {

}
