#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>

TileMap::TileMap(char* path, int rows, int cols, int tileWidth)
{
    rows = rows;
    cols = cols;
    tileWidth = tileWidth;

    std::fstream mapFile(path);
    std::string line;
    allocateArray();
    for (int i=0; i<rows; i++)
    {
        std::getline(mapFile, line);
        for (int j=0; j<cols; j++)
        {
            tileArray[i][j] = line[j];
        }
    }
    mapFile.close();

    dstR.x = 0;
    dstR.y = 0;
    dstR.h = 64;
    dstR.w = 64;
}

TileMap::~TileMap()
{
    deallocateArray();
}

void TileMap::render()
{
    dstR.x = dstR.y = 0;
    int tileID;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; i<cols; j++)
        {
            tileID = tileArray[i][j];
            SDL_RenderCopy(Game::renderer, tileTypes[tileID], NULL, &dstR);
            dstR.x += tileWidth;
        }
        dstR.y += tileWidth;
    }
}

void TileMap::allocateArray()
{
    tileArray = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        tileArray[i] = new int[cols]();
    }
}

void TileMap::deallocateArray()
{
    for (int i=0; i<rows; ++i)
    {
        delete[] tileArray[i];
    }
    delete[] tileArray;
}
