#pragma once
#include "Entity.h"


constexpr int MAX_SECTOR_ENTITIES = 15;

class Sector {
    public:
        Sector();
        ~Sector();
        
    private:
        float xpos;
        float ypos;
        float height;
        float width;
        Entity* sectorEntities[MAX_SECTOR_ENTITIES];
};