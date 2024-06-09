#pragma once
#include "Game.h"

class Entity {
    public:
        Entity(const char* path, int x, int y);
        ~Entity();
        void update();
        void render();
        inline void updateDirection();
    private:
        float xpos;
        float ypos;
        float speed;
        SDL_Texture* objTexture;
        SDL_Rect dstR;
        enum directionType {
            STOP, UP, DOWN, LEFT, RIGHT
        };
        directionType direction;
};
