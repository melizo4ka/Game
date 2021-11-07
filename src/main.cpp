#include <Menu.h>
#include "Engine.h"
#include "TileMap.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(400, 400), "Menu");
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(menu.getPressedItem()){
                                case 1:
                                    window.close();
                                    // load from file
                                    break;
                                case 2:
                                    window.close();
                                    break;
                                case 0:
                                    window.close();
                                    //initialize game
                                    Engine engine;

                                    //game loop
                                    while(engine.running()){
                                        engine.update();
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}