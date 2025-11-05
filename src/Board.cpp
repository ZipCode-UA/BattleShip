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
    if(!inBounds(pos)){
        return false;
    }
    cellType = grid[pos.x][pos.y];
    return true;
}

/**
 * @brief Validate shot location is valid
 * 
 * @param cell Coordinates of cell being shot
 * @return True if shot is valid, otherwise false
 */
bool Board::shotByOpponent(const Coords& cell) {
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
 * @brief Checks if all ships cells have been hit
 *
 * @return True if all ships have been hit, otherwise false
 */
bool Board::allShipsSunk() {
    // Scan the entire grid; if any cell still contains a Ship, not all ships are sunk.
    for (int x = 0; x < boardWidth; ++x) {
        for (int y = 0; y < boardHeight; ++y) {
            if (grid[x][y] == Ship) {
                return false;
            }
        }
    }
    return true;
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
    // Go through the array and set everything to Empty (0)
    for(int i = 0; i < boardWidth; i++) {       // Columns x
        for(int j = 0; j < boardHeight; j++) {   // Rows y
            grid[i][j] = Empty;         // Set cell to Empty (0)
        }
    }

    return;                             // Return to calling function
}

/**
 * @brief Decides where to shoot opponent's board
 * 
 * @param enemyBoard The board of the enemy to shoot
 * @return The location to be shot
 */
Coords Board::shootEnemy(const Board& enemyBoard) {
    return {0, 0};
}
