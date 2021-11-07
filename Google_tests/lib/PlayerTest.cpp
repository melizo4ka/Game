#include "googletest-master/googletest/include/gtest/gtest.h"
#include "../headers/Player.h"

TEST(Player, DefaultConstructor){
    Player pl;
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    ASSERT_EQ(0, playerBounds.left);
    ASSERT_EQ(0, playerBounds.top);
}

TEST(PlayerSuite, TestMove){
    Player pl;
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    //move left
    Keyboard::Key key = Keyboard::Key::A;
    //PlayerState* state = pl.state_->handleInput(*this, map, mapWidth, mapHeight, px, key);

    //check window collision
    ASSERT_EQ(0, playerBounds.left);
    ASSERT_EQ(0, playerBounds.top);

}