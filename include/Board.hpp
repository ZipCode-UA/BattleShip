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
     * @return The CellType of the given cell
     */
    CellTypes getCell(int x, int y) const;

private:
    CellTypes grid[10][10];
};

#endif
