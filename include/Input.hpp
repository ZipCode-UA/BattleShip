/**
 * @file Input.hpp
 */

#ifndef INPUT_HPP
#define INPUT_HPP

#include "Utils.hpp"

/**
 * @brief Prompts, parses, and validates cell user choses to shoot
 *
 * @param[out] cell Cell Coords chosen by user
 */
void getShotCell(Coords& cell);

/**
 * @brief Prompts, parses, and validates user ship placement
 */
void placeShips();

#endif
