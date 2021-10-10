#ifndef GAME_SHOPMENU_H
#define GAME_SHOPMENU_H
#include "SFML/Graphics.hpp"

#define MAX_ITEMS 12

class ShopMenu {
private:
    int selectedItem;
    sf::Font font;
    sf::Text menu[MAX_ITEMS];

public:
    ShopMenu(float width, float height);
    ~ShopMenu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem();
};


#endif //GAME_SHOPMENU_H
