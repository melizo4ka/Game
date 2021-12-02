#ifndef GAME_FISH_H
#define GAME_FISH_H

class Fish {
private:
    void initVariables(int caughtValue);

public:
    int caughtValue;

    Fish(int caughtValue);
    virtual ~Fish() {};

};


#endif //GAME_FISH_H
