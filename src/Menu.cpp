#include "Menu.h"

Menu::Menu(float width, float height) {
    if(!font.loadFromFile("../assets/arial.ttf")){
        //error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("New Game");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Load Game");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

    selectedItem = 0;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for(int i = 0; i < MAX_ITEMS; i++){
        window.draw(menu[i]);
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