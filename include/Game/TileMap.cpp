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
    for (int i=0; i<rows; i++)
    {
        std::getline(mapFile, line);
        for (int j=0; j<cols; j++)
        {
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

TileMap::~TileMap()
{
    deallocateMap();
}

void TileMap::loadTextures()
{
    tileTypes.push_back(TextureManager::loadTexture("assets/topLeftDouble.png"));     // 0
    tileTypes.push_back(TextureManager::loadTexture("assets/topRightDouble.png"));    // 1
    tileTypes.push_back(TextureManager::loadTexture("assets/bottomLeftDouble.png"));  // 2
    tileTypes.push_back(TextureManager::loadTexture("assets/bottomRightDouble.png")); // 3
    tileTypes.push_back(TextureManager::loadTexture("assets/topDouble.png"));         // 4
    tileTypes.push_back(TextureManager::loadTexture("assets/rightDouble.png"));       // 5
    tileTypes.push_back(TextureManager::loadTexture("assets/bottomDouble.png"));      // 6
    tileTypes.push_back(TextureManager::loadTexture("assets/topDouble.png"));         // 7
    tileTypes.push_back(TextureManager::loadTexture("assets/leftDouble.png"));        // 8
    tileTypes.push_back(TextureManager::loadTexture("assets/blank.png"));             // 9
}

void TileMap::render()
{
    dstR.y = dstR.x = 0;
    for (int i=0; i<rows; i++)
    {
        dstR.x = 0;
        for (int j=0; j<cols; j++)
        {
            SDL_RenderCopy(Game::renderer, tileTypes[tileMap[i][j]], NULL, &dstR);
            dstR.x += tileWidth;
        }
        dstR.y += tileWidth;
    }
}

void TileMap::allocateMap()
{
    tileMap = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        tileMap[i] = new int[cols]();
    }
}

void TileMap::deallocateMap()
{
    for (int i=0; i<rows; i++)
    {
        delete[] tileMap[i];
    }
    delete[] tileMap;
}
