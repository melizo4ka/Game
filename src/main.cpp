#include <Menu.h>
#include "Engine.h"
#include "TileMap.h"
#include "Menu.h"
#include <fstream>

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
                                    // load from file
                                    break;
                                    case 2:
                                        window.close();
                                        break;
                                case 0:
                                    window.close();
                                    //initialize game
                                    Engine engine;

                                    bool mapInitialized = false;

                                    //game loop
                                    while(engine.running()){
                                        int array[128];
                                        int *level = engine.readMapFile(array);

                                        //const int* level;
                                        TileMap map;
                                        if (!map.load("assets/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
                                            return -1;
                                        if(!mapInitialized){
                                            engine.getMap(level, 16, 8, 64);
                                            mapInitialized = true;
                                        }
                                        engine.update();
                                        engine.render(map);
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