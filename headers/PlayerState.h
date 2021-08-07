#ifndef GAME_PLAYERSTATE_H
#define GAME_PLAYERSTATE_H

#include <vector>
using namespace std;

class Player;

class PlayerState {
public:
    virtual ~PlayerState();
    virtual PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px);
    virtual void update(Player& pl);
    virtual void enter(Player& pl);
};


#endif //GAME_PLAYERSTATE_H
