#include "TileMap.h"
#include "TextureManager.h"


int lvl1[20][25] = {
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

TileMap::TileMap()
{
    dirt = TextureManager::loadTexture("assets/dirt.png");
    grass = TextureManager::loadTexture("assets/grass.png");
    water = TextureManager::loadTexture("assets/water.png");

    loadMap(lvl1);
    
    srcR.x = srcR.y = 0;
    srcR.w = dstR.w = 32;
    srcR.h = dstR.h = 32;

    dstR.x = dstR.y = 0;
}

TileMap::~TileMap()
{}

void TileMap::loadMap(int arr[20][25])
{
    for (int row=0; row<20; row++)
    {
        for (int col=0; col<25; col++)
        {
            map[row][col] = arr[row][col];
        }
    }
}

void TileMap::drawMap()
{
    int type;
    for (int row=0; row<20; row++)
    {
        for (int col=0; col<25; col++)
        {
            type = map[row][col];
            dstR.x = col * 32;
            dstR.y = row * 32;
            srcR.w = 1000;
            srcR.h = 1000;
            srcR.x = srcR.y = 0;
            switch (type)
            {
                case 0:
                    TextureManager::draw(water, srcR, dstR);
                    break;
                case 1:
                    TextureManager::draw(grass, srcR, dstR);
                    break;
                case 2:
                    TextureManager::draw(dirt, srcR, dstR);
                    break;
                default:
                    break;
            }
        }
    }
}

