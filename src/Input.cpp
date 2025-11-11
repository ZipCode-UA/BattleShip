/**
 * @file Input.cpp
 */

#include "Input.hpp"

#include <cctype>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "Utils.hpp"

/**
 * @brief Checks whether the user entered a valid input string
 *
 * @param[in] input The input string to validate
 *
 * @return true indicates valid input
 */
bool validateCellInput(const std::string &input)
{
    if (std::cin.fail())
    {
        std::cerr << "Invalid cell input\n\n";
        std::cin.clear();
        return false;
    }

    if (input.empty())
    {
        std::cerr << "Invalid cell input\n\n";
        return false;
    }

    if (input.size() < 2 || input.size() > 3) {
        std::cerr << "Invalid input size\n\n";
        return false;
    }

    if (input.size() == 3) {
        if (!std::isdigit(input[2])) {
            std::cerr << "Invalid column number\n\n";
            return false;
        }
    }

    if (!std::isalpha(input[0]))
    {
        std::cerr << "Invalid row letter\n\n";
        return false;
    }

    if ((!std::isdigit(input[1])))
    {
        std::cerr << "Invalid column number\n\n";
        return false;
    }

    return true;
}

/**
 * @brief Checks whether a cell is valid for shooting and clears input buffer
 *
 * @param[in] board The active board object for bounds checking
 * @param[in] cell The Coords object to validate
 *
 * @return true indicates valid cell
 */
bool validateShotCell(const Board &board, const Coords &cell) {
    if (!board.inBounds(cell)) {
        std::cerr << "Invalid cell input - out of bounds\n\n";
        return false;
    }

    return true;
}

/**
 * @brief Prompts, parses, and validates cell user choses to shoot
 *
 * @param[in] board The active board object for bounds checking
 *
 * @retval Coords object containing cell position
 */
Coords getShotCell(const Board &board) {
    while (true) {
        std::cout << "Shoot cell: ";
        std::string input;
        std::getline(std::cin, input);

        if (!validateCellInput(input))
            continue;

        const int DIGITS = input.size() - 1;
        // Convert from index 1 onwards to an integer
        // Subtract 1 to convert user input to index 0 format
        const int NUMBER = std::stoi(input.substr(1, DIGITS)) - 1;
        // Map index[0] to integer starting at index 0
        const int LETTER = std::toupper(input[0]) - 'A';

        Coords cell;
        cell.x = NUMBER;
        cell.y = LETTER;

        if (validateShotCell(board, cell))
            return cell;
    }
}

/**
 * @brief Prompts, parses, and validates user ship placement
 */
void placeShips() {

}
