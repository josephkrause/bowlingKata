#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"

TEST_CASE("Does the Game Exist", "[score]")
{
    //Arrange
    Game *g = new Game;
    bool exists = true;

    //Act
    if(g == NULL)
    {
        exists = false;
    }

    //Assert
    REQUIRE(exists == true);
}

TEST_CASE("Gutter Game Return 0", "[score]")
{
    //Arrange
    Game g;
    int pins = 0;

    //Act
    for(int frame = 0; frame < 20; frame++)
    {
        g.roll(pins);
    }

    //Assert
    REQUIRE(0 == g.scoreGame());
}