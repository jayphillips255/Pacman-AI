#pragma once


class Entity; // Forward declare the Entity class
constexpr int MAX_SECTOR_ENTITIES = 15;

class Sector {
    public:
        Sector();
        ~Sector();
        void addEntity(Entity* entityPtr);
    private:
        float xpos;
        float ypos;
        float height;
        float width;
        int entityIndex;
        Entity* sectorEntities[MAX_SECTOR_ENTITIES];
};