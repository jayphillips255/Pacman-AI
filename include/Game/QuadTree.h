#pragma once
#include <vector>
#include "Entity.h"
#include "Agent.h"



constexpr int MAX_CAPACITY = 50;
constexpr int n = 4; // Number of vertices of a rectangle

class QuadTree {
    public:
        QuadTree();
        QuadTree(float x, float y, float width, float height);
        ~QuadTree();
        bool intersects(Entity* e) const;
        bool insert(Entity* entity);
        bool remove(Entity* entity);
        void checkCollisions(Agent* agent);
    private:
        void subdivide();
        std::vector<Entity*> entities;
        int capacity;
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
