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
        std::cout << "Welcome to BattleShip!\n";
    }

    /**
     * @brief Draw s cells in gird to standard output
     */
    void DrawBoard(const Board& board, bool showShips) {
        // column labels
        std::cout << "   ";
        for (int i = 1; i <= board.boardWidth; ++i) {
            std::cout << std::to_string(i) << ' ';
        }
        std::cout << "\n\n";

        // Top of board's box
        std::cout << "  ┏";
        for (int i = 0; i < board.boardWidth - 1; ++i) {
            std::cout << "━┯";
        }
        std::cout << "━┓\n";

        Coords pos;
        CellTypes curType;
        for (pos.y = 0; pos.y < board.boardHeight; ++pos.y) {

            // Draw row label
            const char rowLabel = 'A';
            std::cout << static_cast<char>(rowLabel + pos.y) << " ┃";

            for (pos.x = 0; pos.x < board.boardWidth; ++pos.x) {
                // Draw Cell
                board.getCell(pos, curType);
                switch (curType)
                {
                case CellTypes::Empty:
                    std::cout << 'E';
                    break;
                 case CellTypes::Ship:
                    if (showShips) std::cout << 'S';
                    else std::cout << 'E';
                    break;
                 case CellTypes::Hit:
                    std::cout << 'H';
                    break;
                 case CellTypes::Miss:
                    std::cout << 'M';
                    break;
                default:
                    break;
                }

                if (pos.x == board.boardWidth - 1) std::cout << "┃";
                else std::cout << "│";
            }

            std::cout << "\n";

            if (pos.y == board.boardHeight - 1) {
                // Draw bottom of board's box
                std::cout << "  ┗";
                for (int i = 0; i < board.boardWidth - 1; ++i)
                    std::cout << "━┷";
                std::cout << "━┛";
            }
            else {
                // Draw inbetween rows
                std::cout << "  ┠";
                for (int i = 0; i < board.boardWidth - 1; ++i)
                    std::cout << "─┼";
                std::cout << "─┨";
            }
            std::cout << "\n";
        }
    }

    /**
     * @brief Draws players board as well as oponents board
     *
     * @param[in] player Current Players board to be drawn with ships shown
     * @param[in] opponent Opposing players board ships to be drawn
     * @param[in] showOpponentShips determines whether the opponents ships will be shown
     */
    void DrawBoard(const Board& player, const Board& opponent, bool showOpponentShips) {

    }

    /**
     * @brief Draws ships in a row or column and gives their name and size
     */
    void DrawShips(const std::vector<ShipStruct>& ships) {

    }

};
