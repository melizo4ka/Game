#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Item.h"
#include "PlayerState.h"

using namespace sf;
using namespace std;


class Player {
private:
    //Inventory items;


    string namePlayer;
    int money;
    int energy;

    void initVariables();
    void initGraphics(int x, int y);
    void setName();

public:
    Sprite sprite;
    Texture standingTexture;
    Texture walkingTexture;

    //constructor and destructor
    Player(int x = 128, int y = 128);
    virtual ~Player();

    void updateWindowBoundsCollision(const RenderTarget* target);

    void setGraphics(Texture texture);

    void update(const RenderWindow* target, vector <int> map, int mapWidth, int mapHeight, int px);
    void render(RenderWindow* window);
    virtual void handleInput(vector <int> map, int mapWidth, int mapHeight, int px);
    Keyboard::Key getInput();
    int getClick(vector <int> map, int mapWidth, int mapHeight, int px, const RenderWindow* window);

    void consumeEnergy();

    PlayerState* state_;
};


#endif //GAME_PLAYER_H
