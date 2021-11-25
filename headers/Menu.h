#ifndef GAME_MENU_H
#define GAME_MENU_H
#include "SFML/Graphics.hpp"

#define MAX_ITEMS 2

class Menu {
private:
    int selectedItem;
    sf::Font font;
    sf::Text menu[MAX_ITEMS];

public:
    Menu(float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() const;

};


#endif //GAME_MENU_H
