/**
 * @file Display.hpp
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Board.hpp"

namespace Display {

    /**
     * @brief Draws an ascii title banner to standard out
     */
    void DrawBanner();

    /**
     * @brief Draws cells in gird to standard output
     *
     * @param[in] board The board being drawn
     * @param[in] showShips Determines whether ships will be shown
     */
    void DrawBoard(const Board& board, bool showShips = true);

    /**
     * @brief Draws players board as well as oponents board
     *
     * @param[in] player Current Players board to be drawn with ships shown
     * @param[in] opponent Opposing players board ships to be drawn
     * @param[in] showOpponentShips determines whether the opponents ships will be shown
     */
    void DrawBoard(const Board& player, const Board& opponent, bool showOpponentShips = false);

    /**
     * @brief Draws the grid layout (borders and labels) for a Battleship board.
     *
     * This function prints an empty grid with row and column labels using ASCII
     * and box-drawing characters. It does not display any cell contents (ships, hits, etc.),
     * only the structure of the board.
     *
     * @param[in] pos The top-left coordinate where the grid should begin drawing on the terminal.
     * @param[in] width The number of columns (horizontal cells) in the board.
     * @param[in] height The number of rows (vertical cells) in the board.
     */
    void DrawEmptyGrid(Coords pos, int width, int height);

    /**
     * @brief Draws the cells of a Battleship board using ANSI colors.
     *
     * @param[in] player The board whose cells will be drawn.
     * @param[in] pos The top-left coordinate where the board begins rendering.
     * @param[in] showShips Determines whether ships should be shown (true for player view, false for opponent view).
     */
    void DrawCells(const Board& player, Coords pos, bool showShips);

    /**
     * @brief Draws ships in a row or column and gives their name and size
     */
    void DrawShips(const std::vector<ShipStruct>& ships);
};

#endif
