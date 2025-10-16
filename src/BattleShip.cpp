/**
 *  @file BattleShip.cpp
 *
 *  @brief Implementation of the game BattleShip
 */

#include <iostream>
#include "Game.hpp"
#include "Display.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void EnableUnicodeWindows() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

int main(int argc, char** argv)
{
    EnableUnicodeWindows();

    Display::DrawBanner();
    std::cout << "Press Enter to Continue ...\n";
    std::cin.get();

    Game game;
    game.run();

    return 0;
}
