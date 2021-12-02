#include <ShopMenu.h>
#include "ShoppingState.h"

std::shared_ptr<PlayerState> ShoppingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
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
                                case 0: //sell salmon
                                    if(pl.inventory[0][1] > 0){
                                        pl.money = pl.money + pl.salmon.caughtValue;
                                        pl.inventory[0][1] = pl.inventory[0][1] - 1;
                                    }
                                    break;
                                case 1: //sell herring
                                    if(pl.inventory[1][1] > 0){
                                        pl.money = pl.money + pl.herring.caughtValue;
                                        pl.inventory[1][1] = pl.inventory[1][1] - 1;
                                    }
                                    break;
                                case 2: // buy potato seed
                                    if(pl.money >= pl.potato.seedValue){
                                        pl.money = pl.money - pl.potato.seedValue;
                                        pl.inventory[2][1] = pl.inventory[2][1] + 1;
                                    }
                                    break;
                                case 3: // sell potatoes
                                    if(pl.inventory[3][1] > 0){
                                        pl.money = pl.money + pl.potato.grownValue;
                                        pl.inventory[3][1] = pl.inventory[3][1] - 1;
                                    }
                                    break;
                                case 4: // buy apple seed
                                    if(pl.money >= pl.apple.seedValue){
                                        pl.money = pl.money - pl.apple.seedValue;
                                        pl.inventory[4][1] = pl.inventory[4][1] + 1;
                                    }
                                    break;
                                case 5: // sell apples
                                    if(pl.inventory[5][1] > 0){
                                        pl.money = pl.money + pl.apple.grownValue;
                                        pl.inventory[5][1] = pl.inventory[5][1] - 1;
                                    }
                                    break;
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
    pl.consumeEnergy();
    pl.sprite.setPosition(pl.startingPosX, pl.startingPosY);
    return std::shared_ptr<PlayerState>(new StandingState());
}

ShoppingState::~ShoppingState() {

}
