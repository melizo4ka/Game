#include <Menu.h>
#include "Engine.h"
#include "TileMap.h"
#include "Menu.h"

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
                                    cout << "load game pressed" << endl;
                                    // load from file
                                    break;
                                    case 2:
                                        window.close();
                                        break;
                                case 0:
                                    cout << "new game pressed" << endl;
                                    window.close();
                                    //initialize game
                                    Engine engine;

                                    bool mapInitialized = false;

                                    //game loop
                                    while(engine.running()){
                                        const int level[] =
                                                {
                                                1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
                                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0,
                                                0, 0, 0, 0, 0, 4, 3, 3, 3, 0, 0, 3, 6, 3, 0, 0,
                                                4, 0, 0, 0, 0, 0, 3, 5, 3, 0, 0, 0, 0, 0, 4, 0,
                                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0,
                                                2, 2, 2, 2, 2, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
                                                2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0,
                                                2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                };

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