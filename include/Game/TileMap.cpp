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
    tileTypes.push_back(TextureManager::loadTexture("assets/tile0.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile1.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile2.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile3.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile4.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile5.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile6.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile7.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile8.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tile9.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileA.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileB.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileC.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileD.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileE.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileF.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileG.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileH.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileI.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileJ.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileK.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileL.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileM.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileN.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileO.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileP.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileQ.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileR.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileS.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileT.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileU.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileV.png"));
    tileTypes.push_back(TextureManager::loadTexture("assets/tileW.png"));
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
