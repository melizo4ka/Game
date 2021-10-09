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
    void initVariables();
    void initGraphics(int x, int y);
    void setName();

public:
    string namePlayer;
    int money;
    int energy;
    int day;
    Sprite sprite;
    Texture standingTexture;
    PlayerState* state_;

    int inventory[6][2]; //items (fish, fish, p seed, p plant, s seed, s plant) and quantity

    int startingPosX = 128;
    int startingPosY = 128;
    int maxEnergy = 50;

    Player(int x = 128, int y = 128);
    virtual ~Player();

    void updateWindowBoundsCollision(const RenderTarget* target);
    void update(const RenderWindow* target, vector <int> map, int mapWidth, int mapHeight, int px);
    void render(RenderWindow* window);
    virtual void handleInput(vector <int> map, int mapWidth, int mapHeight, int px);
    Keyboard::Key getInput();
    int getClick(vector <int> map, int mapWidth, int mapHeight, int px, const RenderWindow* window);
    void initInventory();

    void consumeEnergy();

};


#endif //GAME_PLAYER_H
