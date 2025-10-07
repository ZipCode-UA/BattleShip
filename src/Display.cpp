/**
 * @file Display.cpp
 */

#include "Display.hpp"
#include <iostream>

namespace Display {

    /**
     * @brief Draws an ascii title banner to standard out
     */
    void DrawBanner() {
        std::cout << "Welcome to BattleShip!\n";
    }

    /**
     * @brief Draws cells in gird to standard output
     */
    void DrawGrid(const Board& board, bool showShips = true) {

    }

};
