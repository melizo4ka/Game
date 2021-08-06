#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

#include"Item.h"

#include <iostream>

#include <vector>

using namespace sf;
using namespace std;


class Inventory
{
private:
    vector<Item*> items;

public:
    Inventory();
    virtual ~Inventory();

    void putItem(Item & i);
    //prende numero in base all'oggetto e restituisce l'uso dell'oggetto
    //const_pointer	--- A type that provides a pointer to a const element in a vector.
    void takeItem(vector<Item*> items, Item & i);
    void render();

    bool saveToFile(const string fileName) const;
    bool loadFromFile(const string fileName);

};

#endif //GAME_INVENTORY_H
