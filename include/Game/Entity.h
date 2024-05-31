#pragma once
#include "Game.h"

class Entity
{
    public:
        Entity(const char* path, int x, int y);
        ~Entity();
        void update();
        void render();
    private:
        int xpos;
        int ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcR;
        SDL_Rect dstR;
};