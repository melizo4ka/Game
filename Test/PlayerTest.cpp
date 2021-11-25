#include "lib/googletest-master/googletest/include/gtest/gtest.h"
#include "Player.h"


TEST(Player, CheckConstructor){
    Player pl;
    ASSERT_EQ(30, pl.energy);
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    ASSERT_EQ(128, playerBounds.left);
    ASSERT_EQ(128, playerBounds.top);
}

class PlayerSuite : public ::testing::Test{
protected:
    Player pl;
};
