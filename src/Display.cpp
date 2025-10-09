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
     * @brief Draw s cells in gird to standard output
     */
    void DrawBoard(const Board& board, bool showShips) {
        // Add changes
    }

    /**
     * @brief Draws players board as well as oponents board
     *
     * @param[in] player Current Players board to be drawn with ships shown
     * @param[in] opponent Opposing players board ships to be drawn
     * @param[in] showOpponentShips determines whether the opponents ships will be shown
     */
    void DrawBoard(const Board& player, const Board& opponent, bool showOpponentShips) {

    }

    /**
     * @brief Draws ships in a row or column and gives their name and size
     */
    void DrawShips(const std::vector<ShipStruct>& ships) {

    }

};
