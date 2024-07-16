#pragma once
#include <SDL2/SDL_image.h>
#include "EntityTypes.h"


class Entity {
    public:
        Entity();
        Entity(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        virtual ~Entity() = 0;
        virtual void update() = 0;
        bool AABB(Entity* e1, Entity* e2);
        void render();
        float getx();
        float gety();
        float getw();
        float geth();
        EntityTypes::specificType getSpecificType();
    protected:
        EntityTypes::specificType specificType;
        float xpos;
        float ypos;
        int xGridPos;
        int yGridPos;
        SDL_Rect dstR;
    private:
        float width;
        float height;
        SDL_Texture* tex;
};
