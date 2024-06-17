#pragma once
#include "Game.h"


class TileTypes {
    private:
        enum class tile {
            EMPTY, FOOD, PELLET, DOOR, WALL
        };
        struct tileInfo {
            std::string fileName;
            tile tt;
        };
        const static std::map<char, tileInfo> tileTypes;
};
