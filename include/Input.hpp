/**
 * @file Input.hpp
 */

#ifndef INPUT_HPP
#define INPUT_HPP

#include "Board.hpp"
#include "Utils.hpp"

/**
 * @brief Checks whether the user entered a valid input string
 *
 * @param[in] input The input string to validate
 *
 * @return true indicates valid input
 */
bool validateCellInput(const std::string &input);

/**
 * @brief Checks whether a cell is valid for shooting and clears input buffer
 *
 * @param[in] board The active board object for bounds checking
 * @param[in] cell The Coords object to validate
 *
 * @return true indicates valid cell
 */
bool validateShotCell(const Board &board, const Coords &cell);

/**
 * @brief Prompts, parses, and validates cell user choses to shoot
 *
 * @param[in] board The active board object for bounds checking
 *
 * @retval Coords object containing cell position
 */
Coords getShotCell(const Board &board);

/**
 * @brief Prompts, parses, and validates user ship placement
 */
void placeShips(Board&);

/**
 * @brief 
 */
void placeShip(const ShipStruct& ship, Board& board);

#endif
