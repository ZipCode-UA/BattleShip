/**
 *  @file Game.cpp
 */

#include "Game.hpp"
#include "Display.hpp"

Game::Game() {

}

/**
 * @brief Starts game loop
 */
void Game::run() {

    // Place Ships
    Display::DrawBoard(Player1);
    Display::DrawShips(ships);

    // Generate Opponent Board
    Player2.randomShipPlacement();

    bool inGame = true;

    while (inGame) {
        // Prompt Player for Move

        // Validate Move
        // Update Board

        // Check for Win Condition

        // Display Board

        // Get Oponent's Move

        // Validate Move
        // Update Board

        // Check for Win Condition

        // Display Board
    }

}
