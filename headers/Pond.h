#ifndef GAME_POND_H
#define GAME_POND_H

#include "Object.h"

using namespace sf;
using namespace std;

class Pond :
        public Object{
private:

public:
    Pond(float posX, float posY);
    virtual ~Pond();

    int fishRandom();
};


#endif //GAME_POND_H
