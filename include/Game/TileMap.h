#pragma once
#include "Game.h"
#include <vector>

class TileMap
{
    public:
        TileMap(char* path, int rows, int cols, int tileWidth);
        ~TileMap();
        void render();
    private:
        void allocateArray();
        void deallocateArray();
        int rows;
        int cols;
        int** tileArray;
        std::vector<SDL_Texture*> tileTypes;
        int tileWidth;
        // SDL_Rect srcR;
        SDL_Rect dstR;
};
