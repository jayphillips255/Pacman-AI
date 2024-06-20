#pragma once
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Ghost.h"
#include "Item.h"
#include "EntityTypes.h"


constexpr int MAX_ENTITIES = 800;
constexpr int MAX_ITEMS = 500;
constexpr int MAX_GHOSTS = 4;

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void addEntity(char c, float xpos, float ypos, float height, float width);
    private:
        Entity* entities[MAX_ENTITIES];
        Item items[MAX_ITEMS];
        Ghost ghosts[MAX_GHOSTS];
        Player pacman;
        int entityIndex;
        int ghostIndex;
        int itemIndex;
};
