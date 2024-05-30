#pragma once
#include "Components.h"
#include "PositionComponent.h" // I shouldn't need this because it's included in Components.h ??
#include "TextureManager.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component
{
    public:
        SpriteComponent() = default;
        SpriteComponent(const char* fileName)
        {
            setTexture(fileName);
        }
        void setTexture(const char* fileName) // Previouslly was const char*
        {
            texture = TextureManager::loadTexture(fileName);
        }
        void init() override
        {
            position = &entity->getComponent<PositionComponent>();
            
            srcR.x = srcR.y = 0;
            srcR.w = srcR.h = 32;
            dstR.w = dstR.h = 64;
        }
        void update() override
        {
            dstR.x = position->x();
            dstR.y = position->y();
        }
        void draw() override
        {
            TextureManager::draw(texture, srcR, dstR);
        }
    private:
        PositionComponent* position;
        SDL_Texture* texture;
        SDL_Rect srcR;
        SDL_Rect dstR; 
};
