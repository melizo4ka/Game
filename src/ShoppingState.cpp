#include <ShopMenu.h>
#include "ShoppingState.h"

PlayerState* ShoppingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    sf::RenderWindow menuWindow(sf::VideoMode(300, 600), "Shop Menu");
    ShopMenu shopMenu(menuWindow.getSize().x, menuWindow.getSize().y);

    while (menuWindow.isOpen()){
        sf::Event event;

        while(menuWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            shopMenu.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            shopMenu.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(shopMenu.getPressedItem()){

                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    menuWindow.close();
                    break;
            }
        }
        menuWindow.clear();
        shopMenu.draw(menuWindow);
        menuWindow.display();
    }
    return new StandingState();
}