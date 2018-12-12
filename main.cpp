#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"

TEST_CASE("Does the Game exist", "[score]")
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