/**
 * @file Input.cpp
 */

#include "Input.hpp"

#include <cctype>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "Display.hpp"
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
 * @brief Checks whether the user entered a valid input string
 *
 * @param[in] input The input string to validate
 *
 * @return true indicates valid input
 */
bool validateDirectionInput(const std::string &input){
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

    if (input.size() != 1) {
        std::cerr << "Invalid input size\n\n";
        return false;
    }

    if (!std::isalpha(input[0]))
    {
        std::cerr << "Invalid direction\n\n";
        return false;
    }

    if (std::toupper(input[0]) != 'U'
        && std::toupper(input[0]) != 'D'
        && std::toupper(input[0]) != 'L'
        && std::toupper(input[0]) != 'R'
    ) {
        std::cerr << "Letter does not match directrion\n\n";
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
void placeShips(Board& board) {
    for (const auto ship : ships) {
        Display::DrawBoard(board);
        Display::DrawShips(ships);
        placeShip(ship, board);
    }
}

/**
 * @brief 
 */
void placeShip(const ShipStruct& ship, Board& board) {
    while (true) {
        std::cout << "Enter Cell and Direction for " << ship.name << " (eg. \"A3 D\"): ";
        std::string input;
        std::getline(std::cin, input);

        std::string cellInput = input.substr(0, input.size() - 2);

        if (!validateCellInput(cellInput))
            continue;

        const int DIGITS = cellInput.size() - 1;
        // Convert from index 1 onwards to an integer
        // Subtract 1 to convert user cellInput to index 0 format
        const int NUMBER = std::stoi(cellInput.substr(1, DIGITS)) - 1;
        // Map index[0] to integer starting at index 0
        const int LETTER = std::toupper(cellInput[0]) - 'A';

        Coords cell;
        cell.x = NUMBER;
        cell.y = LETTER;

        std::string dirInput = input.substr(3, 4);
        Direction dir;

        if (!validateDirectionInput(dirInput))
            continue;

        switch (std::toupper(dirInput[0]))
        {
        case 'U':
            dir = UP;
            break;
        case 'D':
            dir = DOWN;
            break;
        case 'L':
            dir = LEFT;
            break;
        case 'R':
            dir = RIGHT;
            break;
        }

        if (!board.validShipPlacement(ship, cell, dir))
            continue;

        board.placeShip(ship, cell, dir);
        break;
    }
}
