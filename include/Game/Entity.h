#pragma once
#include "Game.h"


class Entity {
    public:
        Entity();
        Entity(const char* path, float x, float y, float h, float w);
        virtual ~Entity() = 0;
        virtual void update() = 0;
        void render();
    protected:
        float xpos;
        float ypos;
        SDL_Rect dstR;
    private:
        float height;
        float width;
        SDL_Texture* tex;
};
