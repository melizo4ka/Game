#include "Player.h"
#include <iostream>
#include "PlayerState.h"
#include "StandingState.h"

Player::Player(int x, int y) {
    this->initGraphics(x, y);
    this->initVariables();
    this->state_ = new StandingState();
}

Player::~Player(){

}

void Player::initVariables() {
    this->setName();
    this->money = 1000;
    this->energy = 50;
}

void Player::initGraphics(int x, int y) {
    standingTexture.loadFromFile("assets/standing.png");
    walkingTexture.loadFromFile("assets/walking.png");

    sprite.setTexture(standingTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setPosition(x, y);
}

void Player::setName(){
    cout << "Insert your NAME here: \n";
    cin >> namePlayer;
}

void Player::updateWindowBoundsCollision(const RenderTarget *target) {
    FloatRect playerBounds = this->sprite.getGlobalBounds();
    //left collision
    if(playerBounds.left < 0.f)
        this->sprite.setPosition(0.f, playerBounds.top);
    //right collision
    else if(playerBounds.left + playerBounds.width > target->getSize().x)
        this->sprite.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    //top collision
    if(playerBounds.top < 0.f)
        this->sprite.setPosition(playerBounds.left, 0.f);
    //bottom collision
    else if(playerBounds.top + playerBounds.height > target->getSize().y)
        this->sprite.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}


void Player::updateObjectsCollision(vector <int> map, int mapWidth, int mapHeight, int px) {
    FloatRect playerBounds = this->sprite.getGlobalBounds();
    int objBoundsTop;
    int objBoundsLeft;
    int objBoundsHeight = px;
    int objBoundsWidth = px;

    int i = 0;
    for (int n : map) {
        i++;
        if(n == 1 || n == 3 || n == 4) {
            objBoundsTop = (i % ( mapHeight + 1 )) * 64;
            objBoundsLeft = (i / ( mapHeight )) * 64;
            //left collision (left of the player)
            if (playerBounds.left < objBoundsLeft + objBoundsWidth &&
                (playerBounds.top > objBoundsTop && playerBounds.top < objBoundsTop + objBoundsHeight) &&
                (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)))
                this->sprite.setPosition(objBoundsLeft + objBoundsWidth, playerBounds.top);

            //right collision
            if (playerBounds.left + playerBounds.width > objBoundsLeft &&
                (playerBounds.top > objBoundsTop && playerBounds.top < objBoundsTop + objBoundsHeight) &&
                (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)))
                this->sprite.setPosition(objBoundsLeft - playerBounds.width, playerBounds.top);

            //bottom collision
            if (playerBounds.top + playerBounds.height > objBoundsTop &&
                (playerBounds.left > objBoundsLeft && playerBounds.left < objBoundsLeft + objBoundsHeight) &&
                (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)))
                this->sprite.setPosition(playerBounds.left, objBoundsTop - playerBounds.height);

            //top collision
            if (playerBounds.top < objBoundsTop + objBoundsHeight &&
                (playerBounds.left > objBoundsLeft && playerBounds.left < objBoundsLeft + objBoundsWidth) &&
                (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)))
                this->sprite.setPosition(playerBounds.left, objBoundsTop + objBoundsHeight);
        }
    }
    i = 0;

}


void Player::setGraphics(Texture texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void Player::update(const RenderTarget* target, vector <int> map, int mapWidth, int mapHeight, int px) {
    this->handleInput();
    //window collision detection
    this->updateWindowBoundsCollision(target);

    //objects collision detection
    this->updateObjectsCollision(map, mapWidth, mapHeight, px);
}

void Player::render(RenderWindow* window) {
    window->draw(sprite);
}

void Player::handleInput() {
    PlayerState* state = state_->handleInput(*this);
    if (state != NULL)
    {
        delete state_;
        state_ = state;

        // Call the enter action on the new state.
        state_->enter(*this);
    }
}

void Player::consumeEnergy(){
    energy--;
}