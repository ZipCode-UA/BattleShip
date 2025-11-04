/**
 *  @file Game.cpp
 */

#include "Game.hpp"
#include "Display.hpp"
#include "Input.hpp"
#include <iostream>

Game::Game() {

}

/**
 * @brief Starts game loop
 */
void Game::run() {

    // Place Ships
    Display::DrawBoard(Player1, Player2);
    Display::DrawShips(ships);
    placeShips();

    // Generate Opponent Board
    Player2.randomShipPlacement();

    bool inGame = true;
    bool player1Won;

    while (inGame) {
        Coords curCoords;
        // Get player1 move
        getShotCell(curCoords);
        Player2.shotByOpponent(curCoords);
        Display::DrawBoard(Player1, Player2);

        // Check win condition
        if (Player2.allShipsSunk()) {
            player1Won = true;
            Display::DrawBoard(Player1, Player2, true);
            inGame = false;
            break;
        }
        Display::DrawBoard(Player1, Player2);

        // Get Player2's move 
        curCoords = Board::shootEnemy(Player1);
        Player1.shotByOpponent(curCoords);
        
        // Check for win condition
        if (Player1.allShipsSunk()) {
            player1Won = false;
            Display::DrawBoard(Player1, Player2, true);
            inGame = false;
            break;
        }
        Display::DrawBoard(Player1, Player2);
    }

}
