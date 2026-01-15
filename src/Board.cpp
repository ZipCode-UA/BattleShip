/**
 *  @file Board.cpp
 */

#include "Board.hpp"
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor for Board
 */
Board::Board() {
    std::srand(time(0));
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
    CellTypes cellval = grid[cell.x][cell.y];
    if (cellval == CellTypes::Miss || cellval == CellTypes::Hit)
        return false;

    if(cellval == CellTypes::Ship)
        grid[cell.x][cell.y] = CellTypes::Hit;

    if (cellval == CellTypes::Empty)
        grid[cell.x][cell.y] = CellTypes::Miss;

    return true;
}

/**
 * @brief Checks if given cell is in bounds of board
 *
 * @param[in] pos Position of given cell
 * @return True if cell is in bound, otherwise false
 */
bool Board::inBounds(const Coords& pos) const {
    if (pos.x >= 0 && pos.x < boardWidth
        && pos.y >= 0 && pos.y < boardHeight)
    {
        return true;
    }
    return false;
}

/**
 * @brief Checks if all ships cells have been hit
 *
 * @return True if all ships have been hit, otherwise false
 */
bool Board::allShipsSunk() const {
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
    for (auto a : ships) {
        bool placementFailed = true;
        Coords startPos;
        Direction dir;

        while (placementFailed) {
            // Get random starting position and direction
            startPos = {
                std::rand() % boardWidth,
                std::rand() % boardHeight
            };
            dir = (Direction)(std::rand() % 4);

            placementFailed = !validShipPlacement(a, startPos, dir);
        }

        // Set cells on board to Ship
        placeShip(a, startPos, dir);
    }
}

/**
 * @brief Checks if given ship placement is valid
 *
 * @param[in] ship ship struct being checked
 * @param[in] startPos position the ship will be placed at
 * @param[in] dir the direction the ship is being placed
 * @return True if ship placement is valid, otherwise returns false
 */
bool Board::validShipPlacement(const ShipStruct& ship, const Coords& startPos, const Direction dir) const {
    Coords moveCoords = directionDeltas[dir];

    // Check if that is valid ship placement
    Coords curPos = startPos;
    for (int i = 0; i < ship.size; ++i) {
        if (!inBounds(curPos) || grid[curPos.x][curPos.y] != Empty) {
            return false;
        }
        curPos += moveCoords;
    }
    return true;
}

/**
 * @brief Places ship cells on board
 *
 * @param[in] ship ship struct being checked
 * @param[in] startPos position the ship will be placed at
 * @param[in] dir the direction the ship is being placed
 */
void Board::placeShip(const ShipStruct& ship, const Coords& startPos, Direction dir) {
    // Set cells on board to Ship
    Coords cur = startPos;
    Coords moveCoords = directionDeltas[dir];
    for (int i = 0; i < ship.size; ++i) {
        grid[cur.x][cur.y] = Ship;
        cur += moveCoords;
    }
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
    int randx = rand() % boardWidth;
    int randy = rand() % boardHeight;
    return {randx, randy};
}
