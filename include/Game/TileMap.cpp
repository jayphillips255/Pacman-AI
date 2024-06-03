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
        std::cout << line << std::endl;
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
    tileTypes.push_back(TextureManager::loadTexture("assets/grass.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/dirt.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/water.png"));
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
