#pragma once
#include "EntityTypes.h"
#include "Item.h"
#include "Player.h"
#include "Ghost.h"
#include "QuadTree.h"


constexpr int MAX_ENTITIES = 1000;
constexpr int MAX_ITEMS = 800;
constexpr int MAX_GHOSTS = 4;

class EntityManager {
    public:
        EntityManager();
        EntityManager(float height, float width);
        ~EntityManager();
        void addEntity(char c, float xpos, float ypos, float height, float width);
        void updateEntities();
        void renderEntities();
    private:
        float height;
        float width;
        Entity* entities[MAX_ENTITIES];
        Item items[MAX_ITEMS];
        Ghost ghosts[MAX_GHOSTS];
        Player pacman;
        int entityIndex;
        int ghostIndex;
        int itemIndex;
        QuadTree quadTree;
};
