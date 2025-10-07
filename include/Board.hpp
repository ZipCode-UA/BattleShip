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
    /**
     * @brief Constructor for Board
     */
    Board();

    /**
     * @brief Returns the cell type of a given cell
     * 
     * @param[in] pos Represents the coordinates of the given cell
     * @param[out] cellType The cellType of the given coordinates
     * @return True if coordinates were valid, otherwise returns false 
     */
    bool getCell(const Coords& pos, CellTypes& cellType) const;

    /**
     * @brief Checks if given cell is in bounds of board
     *
     * @param[in] pos Position of given cell
     * @return True if cell is in bounds, otherwise false
     */
    bool inBounds(const Coords& pos) const;

    /**
     * @brief Clears board and randomly places ships on board
     */
    void randomShipPlacement();

    /**
     * @brief Sets all cell states to Empty
     */
    void clearBoard();

public:
    static const int boardWidth = 10;
    static const int boardHeight = 10;

private:
    CellTypes grid[boardWidth][boardHeight];
};

#endif
