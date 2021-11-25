#include <iostream>
#include "Menu.h"

Menu::Menu(float height) {
    try{
        font.loadFromFile("../assets/arial.ttf");
    }
    catch (...){
        std::cerr << "Couldn't find Arial Font" << std::endl;
    }
    for(int i = 0; i < MAX_ITEMS; i++){
        menu[i].setFont(font);
        menu[i].setFillColor(sf::Color::White);
        menu[i].setPosition(sf::Vector2f(100, height / (MAX_ITEMS + 1) * (i+1)));

    }

    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("New Game");
    menu[1].setString("Exit");

    selectedItem = 0;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for(const auto & i : menu){
        window.draw(i);
    }
}

void Menu::moveUp() {
    if(selectedItem - 1 >= 0){
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(selectedItem + 1 < MAX_ITEMS){
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
    }
}

int Menu::getPressedItem() const{
    return selectedItem;
}