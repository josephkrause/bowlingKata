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

TEST_CASE("Single Pin Game Return 20", "[score]")
{
    //Arrange
    Game g;
    int pins = 1;

    //Act
    for(int frame = 0; frame < 20; frame++)
    {
        g.roll(pins);
    }

    //Assert
    REQUIRE(20 == g.scoreGame());
}

TEST_CASE("Spare Then 3 Return 16", "[score]")
{
    //Arrange
    Game g;
    int pins = 0;

    //Act
    g.roll(5);
    g.roll(5);
    g.roll(3);
    for(int frame = 0; frame < 17; frame++)
    {
        g.roll(pins);
    }

    //Assert
    REQUIRE(16 == g.scoreGame());
}

TEST_CASE("Strike Then 3 Then 4 Return 24", "[score]")
{
    //Arrange
    Game g;
    int pins = 0;

    //Act
    g.roll(10);
    g.roll(3);
    g.roll(4);
    for(int frame = 0; frame < 16; frame++)
    {
        g.roll(pins);
    }

    //Assert
    REQUIRE(24 == g.scoreGame());
}