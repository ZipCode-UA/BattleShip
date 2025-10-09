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
      std::cout << R"(
            / /\           / /\             /\ \      /\ \        _\ \         /\ \       / /\        / /\    / /\ /\ \      /\ \    
         / /  \         / /  \            \_\ \     \_\ \      /\__ \       /  \ \     / /  \      / / /   / / / \ \ \    /  \ \   
        / / /\ \       / / /\ \           /\__ \    /\__ \    / /_ \_\     / /\ \ \   / / /\ \__  / /_/   / / /  /\ \_\  / /\ \ \  
       / / /\ \ \     / / /\ \ \         / /_ \ \  / /_ \ \  / / /\/_/    / / /\ \_\ / / /\ \___\/ /\ \__/ / /  / /\/_/ / / /\ \_\ 
      / / /\ \_\ \   / / /  \ \ \       / / /\ \ \/ / /\ \ \/ / /        / /_/_ \/_/ \ \ \ \/___/ /\ \___\/ /  / / /   / / /_/ / / 
     / / /\ \ \___\ / / /___/ /\ \     / / /  \/_/ / /  \/_/ / /        / /____/\     \ \ \    / / /\/___/ /  / / /   / / /__\/ /  
    / / /  \ \ \__// / /_____/ /\ \   / / /     / / /     / / / ____   / /\____\/ _    \ \ \  / / /   / / /  / / /   / / /_____/   
   / / /____\_\ \ / /_________/\ \ \ / / /     / / /     / /_/_/ ___/\/ / /______/_/\__/ / / / / /   / / ___/ / /__ / / /          
  / / /__________/ / /_       __\ \_/_/ /     /_/ /     /_______/\__\/ / /_______\ \/___/ / / / /   / / /\__\/_/___/ / /           
  \/_____________\_\___\     /____/_\_\/      \_\/      \_______\/   \/__________/\_____\/  \/_/    \/_/\/_________\/_/          
      )" << std::endl;
    }

    /**
     * @brief Draws cells in gird to standard output
     */
    void DrawBoard(const Board& board, bool showShips) {

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
