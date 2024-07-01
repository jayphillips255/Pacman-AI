#pragma once
#include <vector>


class Entity;

struct Point {
    float x;
    float y;
    Entity* entity;
};

class QuadTree {
    public:
        QuadTree();
        ~QuadTree();
        bool insertPoint();
    private:
        void subdivide();
        float height;
        float width;
        QuadTree* northWest;
        QuadTree* northEast;
        QuadTree* southWest;
        QuadTree* southEast;
};
