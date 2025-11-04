/**
 * @file Input.cpp
 */

#include "Input.hpp"

#include <iostream>

#include "Board.hpp"
#include "Utils.hpp"

/**
 * @brief Checks whether a cell is valid for shooting and clears input buffer
 *
 * @param[in] board The active board object for bounds checking
 * @param[in] cell The Coords object to validate
 *
 * @return true indicates valid cell
 */
bool validateShotCell(const Board &board, const Coords &cell) {
    bool validFlag = true;

    if ((std::cin.fail()) || !board.inBounds(cell)) {
        std::cerr << "Invalid cell input\n\n";
        validFlag = false;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return validFlag;
}

/**
 * @brief Prompts, parses, and validates cell user choses to shoot
 *
 * @param[in] board The active board object for bounds checking
 *
 * @retval Coords object containing cell position
 */
Coords getShotCell(const Board &board) {
    while(true) {
        std::cout << "Shoot cell: ";

        char number;
        char letter;
        std::cin >> letter >> number;

        Coords cell;
        cell.x = number;
        cell.y = letter;

        if(validateShotCell(board, cell))
            return cell;
    }
}

/**
 * @brief Prompts, parses, and validates user ship placement
 */
void placeShips() {

}
