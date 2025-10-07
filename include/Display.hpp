/**
 * @file Display.hpp
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Board.hpp"

namespace Display {

    /**
     * @brief Draws an ascii title banner to standard out
     */
    void DrawBanner();

    /**
     * @brief Draws cells in gird to standard output
     */
    void DrawGrid(const Board& board, bool showShips = true);

    /**
     * @brief Draws ships in a row or column and gives their name and size
     */
    void DrawShips(const std::vector<ShipStruct>& ships);
};

#endif
