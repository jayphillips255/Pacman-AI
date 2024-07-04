#include "QuadTree.h"


QuadTree::QuadTree() {
    pointIndex = 0;
    divided = false;
    northWest = nullptr;
    northEast = nullptr;
    southWest = nullptr;
    southEast = nullptr;
}

QuadTree::QuadTree(float x, float y, float width, float height) {
    pointIndex = 0;
    divided = false;
    this->x = x;
    this->y = y;
    w = width;
    h = height;
    northWest = nullptr;
    northEast = nullptr;
    southWest = nullptr;
    southEast = nullptr;
}

QuadTree::~QuadTree() {}

bool QuadTree::outOfBounds(Entity* e) {
    bool horizontalOverlap = (e->getx() < this->x) || (e->getx() + e->getw() > this->x + this->w);
    bool verticalOverlap = (e->gety() < this->y) || (e->gety() + e->geth() > this->y + this->h);
    return horizontalOverlap || verticalOverlap;
}

bool QuadTree::insertEntity(Entity* e) {
    if (outOfBounds(e)) {
        return false;
    }
    return true; // Needs implementation
}

void QuadTree::subdivide() {
    northWest = new QuadTree(x,         y,         w / 2, h / 2);
    northEast = new QuadTree(x + w / 2, y,         w / 2, h / 2);
    southWest = new QuadTree(x,         y + h / 2, w / 2, h / 2);
    southEast = new QuadTree(x + w / 2, y + h / 2, w / 2, h / 2);
}
