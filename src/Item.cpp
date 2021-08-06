#include "Item.h"

void Item::initVariables() {

}

Item::Item(){
    this->initVariables();

    this->type = ItemTypes::IT_DEFAULT;
}

Item::~Item(){

}

/*Item* Item::clone() {
    return nullptr;

}*/