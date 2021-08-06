#include "Player.h"
#include "Inventory.h"



Inventory::Inventory(){

}

Inventory::~Inventory() {

}

void Inventory::putItem(Item & i) {
    items.push_back(&i);
}

void Inventory::takeItem(vector<Item*> items, Item & i) {
    /*vector<Item *, std::allocator<Item *>>::iterator it;
    it = find(items.begin(), items.end(), i);
    // If element was found
    if (it != items.end())
    {
        // calculating the position
        int index;
        index = it - items.begin();
        cout << index << endl;
        //replace old selected item with NullObj
        Item * nullItem = new Item();
        // with smart unique_ptr<Item> nullItem(new Item());
        items.at(index) = nullItem;
        //change with replace (items.begin(), items.end(), i, nullItem);
    }
    else {
        // If the element is not present
        cout << "-1" << endl;
    }*/
}

void Inventory::render() {

}

bool Inventory::saveToFile(const string fileName) const {
    return false;
}

bool Inventory::loadFromFile(const string fileName) {
    return false;
}



