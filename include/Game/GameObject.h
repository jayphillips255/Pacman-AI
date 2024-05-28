#pragma once
#include "Game.h"

class GameObject
{
    public:
        GameObject(const char* fileName, SDL_Renderer* ren, int x, int y);
        ~GameObject();
        void update();
        void render();
    private:
        int xpos;
        int ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcR;
        SDL_Rect dstR;
        SDL_Renderer* renderer;
};