#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>


TileMap::TileMap(const char* path, int r, int c, int tw)
{
    rows = r;
    cols = c;
    tileWidth = tw;

    std::fstream mapFile(path);
    std::string line;
    int i = 0;
    allocateMap();
    for (int i=0; i<rows; i++) {
        std::getline(mapFile, line);
        for (int j=0; j<cols; j++) {
            tileMap[i][j] = line[j] - '0';
        }
    }
    mapFile.close();

    loadTextures();
    dstR.x = 0;
    dstR.y = 0;
    dstR.h = tw;
    dstR.w = tw;
}

TileMap::~TileMap() {
    deallocateMap();
}

void TileMap::loadTextures() {
    const int n = 10;
    const int m = 24;
    char path[] = "assets/tile0.png";

    for (int i=0; i<n; i++) {
        tileTypes.push_back(TextureManager::loadTexture(path));
        path[11]++;
    }
    path[11] = 'A';
    for (int i=0; i<m; i++) {
        std::cout << path << std::endl;
        tileTypes.push_back(TextureManager::loadTexture(path));
        path[11]++;
    }    
}

void TileMap::render() {
    dstR.y = 0;
    for (int i=0; i<rows; i++) {
        dstR.x = 0;
        for (int j=0; j<cols; j++) {
            SDL_RenderCopy(Game::renderer, tileTypes[tileMap[i][j]], NULL, &dstR);
            dstR.x += tileWidth;
        }
        dstR.y += tileWidth;
    }
}

void TileMap::allocateMap() {
    tileMap = new int*[rows];
    for (int i=0; i<rows; i++) {
        tileMap[i] = new int[cols]();
    }
}

void TileMap::deallocateMap() {
    for (int i=0; i<rows; i++) {
        delete[] tileMap[i];
    }
    delete[] tileMap;
}
