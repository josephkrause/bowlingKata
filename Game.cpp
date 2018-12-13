//
// Created by josephkrause on 12/12/2018.
//

#include "Game.h"

/**
 * Roll Pins
 * @param frame - Number of pins
 */
void Game::roll(int frame)
{
    rolls[currentRoll] = frame;
    currentRoll++;
}

/**
 * Returns final game score
 */
int Game::scoreGame()
{
    int score = 0;
    int rollNum = 0;

    for(int frame = 0; frame < 10; frame++)
    {
        if(isSpare(rollNum))
        {
            score+= 10 + rolls[rollNum + 2];
        }
        else
        {
            score+= rolls[rollNum] + rolls[rollNum + 1];
        }

        rollNum += 2;
    }

    return score;
}

bool Game::isSpare(int frameIndex)
{
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}
