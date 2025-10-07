/**
 *  @file BattleShip.cpp
 *
 *  @brief Implementation of the game BattleShip
 */

#include <iostream>
#include "Game.hpp"
#include "Display.hpp"

int main(int argc, char** argv)
{

    Display::DrawBanner();
    std::cout << "Press Enter to Continue ...\n";
    std::cin.get();

    Game game;
    game.run();

    return 0;
}
