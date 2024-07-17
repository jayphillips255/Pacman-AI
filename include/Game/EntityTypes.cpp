#include "EntityTypes.h"


const std::map<char, EntityTypes::entityInfo> EntityTypes::entityTypes = {
    {' ', {"", specificType::EMPTY, generalType::EMPTY}}, // You should probably change this if you adapt this project
    {'.', {"assets/food.png", specificType::FOOD, generalType::ITEM}},
    {'@', {"assets/capsule.png", specificType::CAPSULE, generalType::ITEM}},
    {'_', {"assets/door.png", specificType::DOOR, generalType::ITEM}},
    {'A', {"assets/wall0.png", specificType::WALL, generalType::ITEM}},
    {'B', {"assets/wall1.png", specificType::WALL, generalType::ITEM}},
    {'C', {"assets/wall2.png", specificType::WALL, generalType::ITEM}},
    {'D', {"assets/wall3.png", specificType::WALL, generalType::ITEM}},
    {'E', {"assets/wallCorner0.png", specificType::WALL, generalType::ITEM}},
    {'F', {"assets/wallCorner1.png", specificType::WALL, generalType::ITEM}},
    {'G', {"assets/wallCorner2.png", specificType::WALL, generalType::ITEM}},
    {'H', {"assets/wallCorner3.png", specificType::WALL, generalType::ITEM}},
    {'I', {"assets/wallCorner4.png", specificType::WALL, generalType::ITEM}},
    {'J', {"assets/wallCorner5.png", specificType::WALL, generalType::ITEM}},
    {'K', {"assets/wallCorner6.png", specificType::WALL, generalType::ITEM}},
    {'L', {"assets/wallCorner7.png", specificType::WALL, generalType::ITEM}},
    {'0', {"assets/pacman13x13.png", specificType::PACMAN, generalType::PLAYER}},
    {'1', {"assets/inky.png", specificType::INKY, generalType::GHOST}},
    {'2', {"assets/pinky.png", specificType::PINKY, generalType::GHOST}},
    {'3', {"assets/blinky.png", specificType::BLINKY, generalType::GHOST}},
    {'4', {"assets/clyde.png", specificType::CLYDE, generalType::GHOST}}
};
