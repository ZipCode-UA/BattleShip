/**
 * @file Utils.hpp
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

/**
 * @enum CellTypes
 *
 * @brief Represents four possible states a cell can be in
 */
enum CellTypes {
    Empty,
    Ship,
    Hit,
    Miss
};

/**
 * @struct ShipStruct
 *
 * @brief contains the name and size of ships
 */
struct ShipStruct {
    std::string name;
    int size;
};

const std::vector<ShipStruct> ships = {
    {"Carrier", 5},
    {"Battleship", 4},
    {"Destroyer", 3},
    {"Submarine", 3},
    {"Patrol Boat", 2}
};

#endif
