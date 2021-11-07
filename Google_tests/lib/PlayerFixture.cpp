#include <StandingState.h>
#include "googletest-master/googletest/include/gtest/gtest.h"

class PlayerSuite : public ::testing::Test{
protected:
    virtual void SetUp(){
        pl.startingPosX = 0;
        pl.startingPosY = 128;
        pl.state_ = new StandingState();
    }
    Player pl;
};
