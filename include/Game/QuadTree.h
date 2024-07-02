#pragma once
#include <vector>


constexpr int CAPACITY = 4;
class Entity; // Forward declare Entity

struct Point {
    float x;
    float y;
    Entity* entity;
};

class QuadTree {
    public:
        QuadTree();
        QuadTree(float x, float y, float width, float height);
        ~QuadTree();
        bool insertPoint(float x, float y, Entity* entity);
    private:
        void subdivide();
        Point* points[CAPACITY];
        float x;
        float y;
        float w;
        float h;
        QuadTree* northEast;
        QuadTree* northWest;
        QuadTree* southEast;
        QuadTree* southWest;
};
