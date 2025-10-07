/**
 *  @file Board.hpp
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Utils.hpp"

/**
 * @class Board
 *
 * @brief Represents a grid of cells for the game
 */
class Board {
public:
    Board();

    /**
     * @brief Returns the cell type of a given cell
     * 
     * @param[in] x Represents the x coordinate
     * @param[in] y Represents the y coordinate
     * @param[out] cellType The cellType of the given coordinates
     * @return True if coordinates were valid, otherwise returns false 
     */
    bool Board::getCell(int x, int y, CellTypes& cellType) const;

    static const int boardWidth = 10;
    static const int boardHeight = 10;

private:
    CellTypes grid[boardWidth][boardHeight];
};

#endif
