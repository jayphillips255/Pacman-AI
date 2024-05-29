#pragma once
#include "Game.h"

class TileMap
{
    public:
        TileMap();
        ~TileMap();
        void loadMap(int arr[20][25]);
        void drawMap();
    private:
        SDL_Rect srcR;
        SDL_Rect dstR;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int map[20][25];

};
