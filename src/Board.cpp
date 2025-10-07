/**
 *  @file Board.cpp
 */

#include "Board.hpp"

/**
 * @brief Constructor for Board
 */
Board::Board() {
    clearBoard();
}

/**
 * @brief Returns the cell type of a given cell
 * 
 * @param[in] pos Represents the coordinates of the given cell
 * @param[out] cellType The cellType of the given coordinates
 * @return True if coordinates were valid, otherwise returns false 
 */
bool Board::getCell(const Coords& pos, CellTypes& cellType) const {
    return false;
}

/**
 * @brief Checks if given cell is in bounds of board
 *
 * @param[in] pos Position of given cell
 * @return True if cell is in bounds, otherwise false
 */
bool Board::inBounds(const Coords& pos) const {
    return false;
}

/**
 * @brief Clears board and randomly places ships on board
 */
void Board::randomShipPlacement() {

}

/**
 * @brief Sets all cell states to Empty
 */
void Board::clearBoard() {

}
