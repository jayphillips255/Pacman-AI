#pragma once
#include <SDL2/SDL_image.h>
#include "EntityTypes.h"
#include "Sector.h"


class Entity {
    public:
        Entity();
        Entity(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w);
        virtual ~Entity() = 0;
        virtual void update() = 0;
        bool AABB(Entity& e1, Entity& e2);
        inline void setSector(Sector* sec);
        void render();
    protected:
        EntityTypes::specificType specificType;
        float xpos;
        float ypos;
        SDL_Rect dstR;
        Sector* currentSector;
    private:
        float height;
        float width;
        SDL_Texture* tex;
};
