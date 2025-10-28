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
     * @brief Validate shot location is valid
     * 
     * @param cell Coordinates of cell being shot
     * @return True if shot is valid, otherwise false
     */
    bool shotByOpponent(const Coords& cell);

    /**
     * @brief Checks if given cell is in bounds of board
     *
     * @param[in] pos Position of given cell
     * @return True if cell is in bounds, otherwise false
     */
    bool inBounds(const Coords& pos) const;

    /**
     * @brief Checks if all ships cells have been hit
     *
     * @return True if all ships have been hit, otherwise false
     */
    bool allShipsSunk();

    /**
     * @brief Clears board and randomly places ships on board
     */
    void randomShipPlacement();

    /**
     * @brief Sets all cell states to Empty
     */
    void clearBoard();

    /**
     * @brief Decides where to shoot opponent's board
     * 
     * @param[in] enemyBoard The board of the enemy to shoot
     * @return The location to be shot
     */
    static Coords shootEnemy(const Board& enemyBoard);

    /**
     * @brief Checks if a shot on this cell is valid
     *
     * @param[in] coordinates to check
     * @return Returns false if coords given are not valid to be shot, otherwise true
     */
    bool isValidShotLocation(const Coords& coords) const {
        if (!inBounds(coords)) {
            return false;
        }

        if (grid[coords.x][coords.y] == Miss || grid[coords.x][coords.y] == Hit) {
            return false;
        }

        return true;
    }

public:
    static const int boardWidth = 10;
    static const int boardHeight = 10;

private:
    CellTypes grid[boardWidth][boardHeight];
};

#endif
