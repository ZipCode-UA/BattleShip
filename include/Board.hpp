/**
 *  @file Board.hpp
 */

#ifndef BOARD_HPP
#define BOARD_HPP

/**
 * @enum CellTypes
 *
 * @brief Represents four possible states a cell can be in
 */
enum CellTypes {
    Empty,
    Ship,
    Hit,
    Miss
};

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
bool Board::getCell(int x, int y) const;

private:
    CellTypes grid[10][10];
};

#endif
