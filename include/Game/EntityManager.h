#pragma once
#include "CONSTANTS.h"
#include "EntityTypes.h"
#include "Item.h"
#include "Player.h"
#include "Ghost.h"
#include "QuadTree.h"


class EntityManager {
    public:
        EntityManager();
        EntityManager(float width, float height);
        ~EntityManager();
        void addEntity(char c, int xGridPos, int yGridPos, float width, float height);
        void updateEntities();
        void renderEntities();
        bool wallMatrix[GAME_WIDTH][GAME_HEIGHT];
    private:
        inline void updateWallMatrix(EntityTypes::specificType st, int xGridPos, int yGridPos);
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
