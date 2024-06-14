#pragma once
#include "Game.h"
#include "EntityMap.h"

class Entity {
    public:
        Entity(const char* path, float x, float y, int height, int width);
        ~Entity();
        void update();
        void render();
        inline void updatePosition();
        inline void updateDirection();
        bool wallColission();
    private:
        int height;
        int width;
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
