#include "ShopMenu.h"

ShopMenu::ShopMenu(float width, float height) {
    if(!font.loadFromFile("../assets/arial.ttf")){
        //error
    }

    for(int i = 0; i < (MAX_ITEMS); i++){
        menu[i].setFont(font);
        menu[i].setCharacterSize(20);
        menu[i].setFillColor(sf::Color::White);
        menu[i].setPosition(sf::Vector2f(10, height / (MAX_ITEMS + 1) * i));
    }

    menu[0].setString("Salmon - buy");
    menu[1].setString("Salmon - sell");

    menu[2].setString("Herring - buy");
    menu[3].setString("Herring - sell");

    menu[4].setString("Potato seed - buy");
    menu[5].setString("Potato seed - sell");

    menu[6].setString("Potato - buy");
    menu[7].setString("Potato - sell");

    menu[8].setString("Apple seed - buy");
    menu[9].setString("Apple seed - sell");

    menu[10].setString("Apple - buy");
    menu[11].setString("Apple - sell");

    selectedItem = 0;
    menu[0].setFillColor(sf::Color::Red);
}

ShopMenu::~ShopMenu() {

}

void ShopMenu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < MAX_ITEMS; i++){
        window.draw(menu[i]);
    }
}

void ShopMenu::moveUp() {
    if(selectedItem - 1 >= 0){
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
    }
}

void ShopMenu::moveDown() {
    if(selectedItem + 1 < (MAX_ITEMS)){
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
    }
}

int ShopMenu::getPressedItem(){
    return selectedItem;
}
