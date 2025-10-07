/**
 *  @file BattleShip.cpp
 *
 *  @brief Implementation of the game BattleShip
 */

#include <iostream>
#include "Game.hpp"

int main(int argc, char** argv)
{

    std::cout << "Press Enter to Continue ...\n";
    std::cin.get();

    Game game;
    game.run();

    return 0;
}
