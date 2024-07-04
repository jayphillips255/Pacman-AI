#pragma once
#include <vector>
#include "Entity.h"

struct Point {
    float x;
    float y;
    Entity* Entity;
};

constexpr int CAPACITY = 4;
constexpr int n = 4; // Number of vertices of a rectangle

class QuadTree {
    public:
        QuadTree();
        QuadTree(float x, float y, float width, float height);
        ~QuadTree();
        bool outOfBounds(Entity* e);
        bool insertEntity(Entity* entity);
    private:
        void subdivide();
        Point points[CAPACITY];
        int pointIndex;
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
