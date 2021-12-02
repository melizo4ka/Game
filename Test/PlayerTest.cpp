#include "googletest-master/googletest/include/gtest/gtest.h"
#include "../headers/Player.h"

//constructor values
TEST(Player, CheckConstructor){
    int playerStartX = 128;
    int playerStartY = 128;
    Player player = Player (playerStartX, playerStartY, 5.f);
    ASSERT_EQ(30, player.energy);
    ASSERT_EQ(1000, player.money);

    Vector2f position = player.sprite.getPosition();
    ASSERT_EQ(128, position.x);
    ASSERT_EQ(128, position.y);

    ASSERT_FALSE(player.pondClicked);
    ASSERT_FALSE(player.blankClicked);
    ASSERT_FALSE(player.harvestableClicked);
    for (auto & i : player.inventory){
        ASSERT_EQ(i[1], 0);
    }

    player.consumeEnergy();
    ASSERT_EQ(29, player.energy);
}
