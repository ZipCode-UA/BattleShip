/**
 *  @file Board.cpp
 */

#include "Board.hpp"

/**
 * @brief Constructor for Board
 */
Board::Board() {

}

/**
 * @brief Returns the cell type of a given cell
 * 
 * @param[in] x Represents the x coordinate
 * @param[in] y Represents the y coordinate
 * @param[out] cellType The cellType of the given coordinates
 * @return True if coordinates were valid, otherwise returns false 
 */
bool Board::getCell(int x, int y, CellTypes& cellType) const {
    return false;
}

/**
 * @brief Checks if given cell is in bounds of board
 * 
 * @return True if cell is in bounds, otherwise false
 */
bool Board::inBounds(int x, int y) {
    return false;
}
