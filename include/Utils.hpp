/**
 * @file Utils.hpp
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

/**
 * @struct Coords
 * 
 * @brief Coordinates of cells starting at 0
 */
struct Coords {
    int x;
    int y;

    Coords operator+(const Coords& rhs) const {
        Coords newCoords;
        newCoords.x = x + rhs.x;
        newCoords.y = y + rhs.y;
        return newCoords;
    }

    Coords& operator+=(const Coords& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};

/**
 * @enum Direction
 */
enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

constexpr Coords directionDeltas[] = {
    { 0, -1 }, // UP
    { 0,  1 }, // DOWN
    { -1, 0 }, // Left
    {  1, 0 }, // Right
};

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
