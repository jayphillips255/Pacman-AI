#pragma once
#include <map>
#include <iostream>


class EntityTypes {
    public:
        enum class specificType {
            PACMAN, INKY, PINKY, BLINKY, CLYDE, FOOD, CAPSULE, DOOR, WALL
        };
        enum class generalType {
            PLAYER, GHOST, ITEM
        };
        struct entityInfo {
            const char* fileName;
            specificType st; // Specific Type
            generalType gt; // General Type
        };
        const static std::map<char, entityInfo> entityTypes;
};
