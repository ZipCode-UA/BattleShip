/**
 * @file Display.cpp
 */

#include "Display.hpp"
#include <iostream>

namespace Display {

    /**
     * @brief Draws an ascii title banner to standard out
     */
    void DrawBanner() {
        std::cout << "\033[2J";
        std::cout << "\033[1;1H";
        std::cout << "Welcome to BattleShip!\nPress Enter to Continue!";
    }

    /**
     * @brief Draws players board as well as oponents board
     *
     * @param[in] player Current Players board to be drawn with ships shown
     * @param[in] opponent Opposing players board ships to be drawn
     * @param[in] showOpponentShips determines whether the opponents ships will be shown
     */
    void DrawBoard(const Board& player, const Board& opponent, bool showOpponentShips) {

        // Reset Screen
        std::cout << "\033[2J";

        // Draw Player 1 Board
        std::cout << "\033[1;1H";
        std::cout << "   Your Board";
        std::cout << "\033[1B";
        DrawEmptyGrid({1, 3}, player.boardWidth, player.boardHeight);
        DrawCells(player, {1, 3}, true);

        // Draw Player 2 Board
        std::cout << "\033[1;1H";
        std::cout << std::string("\033[" + std::to_string(player.boardWidth * 2 + 5) + "C");
        std::cout << "   Opponent's Board";
        std::cout << "\033[1B";
        DrawEmptyGrid({26, 3}, opponent.boardWidth, opponent.boardHeight);
        DrawCells(opponent, {26, 3}, showOpponentShips);

        // Set cursor Below Boards
        std::cout << "\033[1G";
    }

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
    void DrawEmptyGrid(Coords pos, int width, int height) {
        std::cout << std::string("\033[" + std::to_string(pos.y) + ";" + std::to_string(pos.x) + "H");

        // column labels
        std::cout << "   ";
        for (int i = 1; i <= width; ++i) {
            std::cout << std::to_string(i) << ' ';
        }
        std::cout << "\033[2B";

        // Top of board's box
        std::cout << std::string("\033[" + std::to_string(pos.x) + "G");
        std::cout << "  ┏";
        for (int i = 0; i < height - 1; ++i) {
            std::cout << "━┯";
        }
        std::cout << "━┓\033[1B";
        std::cout << std::string("\033[" + std::to_string(pos.x) + "G");

        CellTypes curType;
        Coords cur;
        for (cur.y = 0; cur.y < width; ++cur.y) {

            // Draw row label
            const char rowLabel = 'A';
            std::cout << static_cast<char>(rowLabel + cur.y) << " ┃";

            for (cur.x = 0; cur.x < height; ++cur.x) {
                std::cout << " ";
                if (cur.x == width - 1) std::cout << "┃";
                else std::cout << "│";
            }

            std::cout << std::string("\033[" + std::to_string(pos.x) + "G");
            std::cout << "\033[1B";

            if (cur.y == height - 1) {
                // Draw bottom of board's box
                std::cout << "  ┗";
                for (int i = 0; i < width - 1; ++i)
                    std::cout << "━┷";
                std::cout << "━┛";
                std::cout << std::string("\033[" + std::to_string(pos.x) + "G");
            }
            else {
                // Draw inbetween rows
                std::cout << "  ┠";
                for (int i = 0; i < height - 1; ++i)
                    std::cout << "─┼";
                std::cout << "─┨";
                std::cout << std::string("\033[" + std::to_string(pos.x) + "G");
            }
            std::cout << "\033[1B";
        }
    }

    /**
     * @brief Draws the cells of a Battleship board using ANSI colors.
     *
     * @param[in] player The board whose cells will be drawn.
     * @param[in] pos The top-left coordinate where the board begins rendering.
     * @param[in] showShips Determines whether ships should be shown (true for player view, false for opponent view).
     */
    void DrawCells(const Board& player, Coords pos, bool showShips) {

        std::cout << std::string("\033[" + std::to_string(pos.y + 3) + ";" + std::to_string(pos.x + 3) + "H");
        Coords cur;
        for (cur.y = 0; cur.y < player.boardHeight; ++cur.y) {
            for (cur.x = 0; cur.x < player.boardWidth; ++cur.x) {
                CellTypes cellType;
                player.getCell(cur, cellType);

                std::string colorCode;

                switch (cellType) {
                    case CellTypes::Empty:
                        colorCode = "\033[0m";
                        break;
                    case CellTypes::Ship:
                        if (showShips)
                            colorCode = "\033[48;5;244m";
                        break;
                    case CellTypes::Hit:
                        colorCode = "\033[48;5;1m";
                        break;
                    case CellTypes::Miss:
                        colorCode = "\033[48;5;6m";
                        break;
                    default:
                        colorCode = "\033[0m";
                        break;
                }

                // Print one colored cell (space with background)
                std::cout << colorCode << " " << "\033[0m";

                std::cout << "\033[1C";
            }
            std::cout << "\033[2B";
            std::cout << std::string("\033[" + std::to_string(cur.x * 2) + "D");
        }
    }

    /**
     * @brief Draws ships in a row or column and gives their name and size
     */
    void DrawShips(const std::vector<ShipStruct>& ships) {

    }

};
