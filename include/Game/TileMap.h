#pragma once
#include "Game.h"
#include <vector>

class TileMap
{
    public:
        TileMap(const char* path, int r, int c, int tw);
        ~TileMap();
        void render();
    private:
        inline void loadTextures();
        void allocateMap();
        void deallocateMap();
        int rows;
        int cols;
        int** tileMap;
        std::vector<SDL_Texture*> tileTypes;
        int tileWidth;
        SDL_Rect dstR;
};
