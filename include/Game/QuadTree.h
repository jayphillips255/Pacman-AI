#pragma once
#include <vector>
#include "Entity.h"
#include "Agent.h"

/*
NOTE: There is a problem with collision detection for lower capacities.
      Before lowering the max capacity for a more efficent quadtree, the collision detection must be adressed.
      The problem is likely the insertion of entities.
*/

constexpr int MAX_CAPACITY = 75;
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
