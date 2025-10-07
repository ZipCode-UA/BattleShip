/**
 *  @file Game.hpp
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
public:
    Game();

    void run();
private:
    Board Player1;
    Board Player2;
};

#endif
