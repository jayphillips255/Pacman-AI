#pragma once
#include "EntityTypes.h"
#include "Item.h"
#include "Player.h"
#include "Ghost.h"
#include "QuadTree.h"


constexpr int MAX_ENTITIES = 1000;
constexpr int MAX_ITEMS = 800;
constexpr int MAX_AGENTS = 5;
constexpr int MAX_GHOSTS = 4;

class EntityManager {
    public:
        EntityManager();
        EntityManager(float width, float height);
        ~EntityManager();
        void addEntity(char c, float xpos, float ypos, float width, float height);
        void updateEntities();
        void renderEntities();
    private:
        float height;
        float width;
        Entity* entities[MAX_ENTITIES];
        Agent* agents[MAX_AGENTS];
        Ghost ghosts[MAX_GHOSTS];
        Item items[MAX_ITEMS];
        Player pacman;
        int entityIndex;
        int agentIndex;
        int ghostIndex;
        int itemIndex;
        QuadTree quadTree;
};
