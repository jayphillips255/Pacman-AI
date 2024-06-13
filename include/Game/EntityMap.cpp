#include "EntityMap.h"
#include "TextureManager.h"
#include <fstream>


EntityMap::

EntityMap::EntityMap() {}

EntityMap::EntityMap(const char* path, int r, int c, int tw) {
    rows = r;
    cols = c;
    tileWidth = tw;
    dstR.h = dstR.w = tw;
    dstR.x = dstR.y = 0;

    std::ifstream mapFile(path);
    std::string line;
    allocateMap();

    for (std::size_t i=0; i<rows; i++) {
        std::getline(mapFile, line); 
        for (std::size_t j=0; j<cols; j++) {
            updateTile(line[j], i, j);
        }
    }
    mapFile.close();

    textureMap[FOOD] = TextureManager::loadTexture("assets/food.png");
    textureMap[PELLET] = TextureManager::loadTexture("assets/pellet.png");
}

EntityMap::~EntityMap() {
    deallocateMap();
}

EntityMap::entityType EntityMap::getType(int x, int y) {
    return tileMap[x][y];
}

void EntityMap::setType(int x, int y, EntityMap::entityType type) {
    tileMap[x][y] = type;
}

void EntityMap::render() {
    dstR.y = 0;
    for (std::size_t i=0; i<rows; i++) {
        dstR.x = 0;
        for (std::size_t j=0; j<cols; j++) {
            if (tileMap[i][j] == PELLET || tileMap[i][j] == FOOD) {
                SDL_RenderCopy(Game::renderer, textureMap[tileMap[i][j]], NULL, &dstR);
            }
            dstR.x += tileWidth;
        }
        dstR.y += tileWidth;
    }
}

int EntityMap::getTileWidth() {
    return tileWidth;
}

inline void EntityMap::allocateMap() {
    tileMap = new entityType*[rows];
    for (std::size_t i=0; i<rows; i++) {
        tileMap[i] = new entityType[cols]();
    }
}

inline void EntityMap::deallocateMap() {
    for (std::size_t i=0; i<rows; i++) {
        delete[] tileMap[i];
    }
    delete[] tileMap;
}

void EntityMap::updateTile(char& c, std::size_t& i, std::size_t& j) {
    switch (c) {
        case ' ':
            tileMap[i][j] = EMPTY;
            break;
        case 'H':
            tileMap[i][j] = WALL;
            break;
        case '_':
            tileMap[i][j] = DOOR;
            break;
        case '.':
            tileMap[i][j] = FOOD;
            break;
        case '@':
            tileMap[i][j] = PELLET;
            break;
        default:
            break;
    }
}
