#pragma once
#include <map>
#include <iostream>


class TileTypes {
    public:
        enum tile {
            EMPTY = 0, FOOD, CAPSULE, DOOR, WALL, PACMAN, INKY, PINKY, BLINKY, CLYDE
        };
    private:
        struct tileInfo {
            std::string fileName;
            tile tt;
        };
        const static std::map<char, tileInfo> tileTypes;
};
