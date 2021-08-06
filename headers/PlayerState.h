#ifndef GAME_PLAYERSTATE_H
#define GAME_PLAYERSTATE_H

class Player;

class PlayerState {
public:
    virtual ~PlayerState();
    virtual PlayerState* handleInput(Player& pl);
    virtual void update(Player& pl);
    virtual void enter(Player& pl);
};


#endif //GAME_PLAYERSTATE_H
