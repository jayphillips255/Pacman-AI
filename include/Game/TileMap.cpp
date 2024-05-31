#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>

TileMap::TileMap(char* path)
{
    std::fstream mapFile(path);
    std::string line;
    int i = 0;
    while (std::getline(mapFile, line))
    {
        for (unsigned int j=0; j<line.size(); j++)
        {
            tileArray[i][j] = line[j];
        }
        i++;
    }
    mapFile.close();

    srcR.x = srcR.y = 0;
    srcR.w = dstR.w = 32;
    srcR.h = dstR.h = 32;
    dstR.x = dstR.y = 0;
}

TileMap::~TileMap()
{}

void TileMap::render()
{
    
}

