#include "TileTypes.h"


const std::map<char, TileTypes::tileInfo> TileTypes::tileTypes = {
    {' ', {"assets/empty.png", tile::EMPTY}},
    {'.', {"assets/food.png", tile::FOOD}},
    {'@', {"assets/pellet.png", tile::PELLET}},
    {'_', {"assets/door.png", tile::DOOR}},
    {'A', {"assets/wall0.png", tile::WALL}},
    {'B', {"assets/wall1.png", tile::WALL}},
    {'C', {"assets/wall2.png", tile::WALL}},
    {'D', {"assets/wall3.png", tile::WALL}},
    {'E', {"assets/wallCorner0.png", tile::WALL}},
    {'F', {"assets/wallCorner1.png", tile::WALL}},
    {'G', {"assets/wallCorner2.png", tile::WALL}},
    {'H', {"assets/wallCorner3.png", tile::WALL}}
};
