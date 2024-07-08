#pragma once
#include <vector>
#include "Entity.h"
#include "Agent.h"


constexpr int CAPACITY = 4;
constexpr int n = 4; // Number of vertices of a rectangle

class QuadTree {
    public:
        QuadTree();
        QuadTree(float x, float y, float width, float height);
        ~QuadTree();
        bool outOfBounds(Entity* e) const;
        bool intersects(Entity* e) const;
        bool insertEntity(Entity* entity);
        bool removeEntity(Entity* entity);
        void checkCollision(Agent* entity);
    private:
        void subdivide();
        Entity* entities[CAPACITY];
        int entityIndex;
        bool divided;
        float x;
        float y;
        float w;
        float h;
        QuadTree* northWest;
        QuadTree* northEast;
        QuadTree* southWest;
        QuadTree* southEast;
};
