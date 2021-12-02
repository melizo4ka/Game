#include "googletest-master/googletest/include/gtest/gtest.h"
#include "../headers/Player.h"
#include "../headers/TileMap.h"

class PlayerSuite : public ::testing::Test {
protected:
    int playerStartX = 128;
    int playerStartY = 128;
    Player player = Player (playerStartX, playerStartY, 2.f);

    TileMap tilemap;
    int map[36] =
            {
            0, 0, 0, 3, 3, 3,
            0, 0, 0, 3, 5, 3,
            0, 4, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 4, 0, 0, 0,
            };
    int windowWidth = 384;
    int windowHeight = 384;
    int mapWidth = 6;
    int mapHeight = 6;
    VideoMode videoMode = VideoMode(windowWidth, windowHeight);
    Event sfmlEvent;
    int pixels = 64;

};


//movement changes player's coords
TEST_F(PlayerSuite, TestMove) {
    std::shared_ptr<RenderWindow> window = std::make_shared<RenderWindow> (videoMode, "TestMove", Style::Close | Style::Titlebar);
    while(window->isOpen()){
        //update
        tilemap.load("../assets/tileset.png", sf::Vector2u(32, 32), map, 6, 6);

        //pollEvent
        while(window->pollEvent(sfmlEvent)){
            //window closing
            if(sfmlEvent.type == Event::Closed)
                window->close();
            if(sfmlEvent.type == Event::KeyPressed){
                if(sfmlEvent.key.code == Keyboard::Escape)
                    window->close();
            }
        }
        player.update(window, map, mapWidth, mapHeight, pixels);

        //render
        window->clear();
        window->draw(tilemap);
        player.render(window);

        window->display();
    }
    //checks that the position is different from the starting one
    Vector2f position = player.sprite.getPosition();
    ASSERT_NE(playerStartX, position.x);
    ASSERT_NE(playerStartY, position.y);

}

//if collision with window bound then doesnt go further
TEST_F(PlayerSuite, TestBounds) {
    std::shared_ptr<RenderWindow> window = std::make_shared<RenderWindow> (videoMode, "TestBounds", Style::Close | Style::Titlebar);
    while(window->isOpen()){
        //update
        tilemap.load("../assets/tileset.png", sf::Vector2u(32, 32), map, 6, 6);

        //pollEvent
        while(window->pollEvent(sfmlEvent)){
            //window closing
            if(sfmlEvent.type == Event::Closed)
                window->close();
            if(sfmlEvent.type == Event::KeyPressed){
                if(sfmlEvent.key.code == Keyboard::Escape)
                    window->close();
            }
        }
        player.update(window, map, mapWidth, mapHeight, pixels);

        //render
        window->clear();
        window->draw(tilemap);
        player.render(window);
        window->display();
    }
    Vector2f position = player.sprite.getPosition();
    ASSERT_GE(position.x, 0);
    ASSERT_GE(position.y, 0);

}

//when in shop and choose buy 1 potato seed - #2 in inventory
TEST_F(PlayerSuite, TestInventory) {
    std::shared_ptr<RenderWindow> window = std::make_shared<RenderWindow> (videoMode, "TestInventory", Style::Close | Style::Titlebar);

    int startPotSeed = player.inventory[2][1];
    int startMoney = player.money;

    while(window->isOpen()){
        //update
        tilemap.load("../assets/tileset.png", sf::Vector2u(32, 32), map, 6, 6);

        //pollEvent
        while(window->pollEvent(sfmlEvent)){
            //window closing
            if(sfmlEvent.type == Event::Closed)
                window->close();
            if(sfmlEvent.type == Event::KeyPressed){
                if(sfmlEvent.key.code == Keyboard::Escape)
                    window->close();
            }
        }
        player.update(window, map, mapWidth, mapHeight, pixels);

        //render
        window->clear();
        window->draw(tilemap);
        player.render(window);
        window->display();
    }
    //consume money
    ASSERT_EQ(startMoney - player.potato.seedValue, player.money);

    //add to the inventory
    ASSERT_EQ(player.inventory[2][1], startPotSeed + 1);
}
