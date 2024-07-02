#include "QuadTree.h"


QuadTree::QuadTree() {}

QuadTree::QuadTree(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    w = width;
    h = height;
}

QuadTree::~QuadTree() {}

bool QuadTree::insertPoint(float x, float y, Entity* entity) {
    return true; // Needs implementation
}

void QuadTree::subdivide() {
    northWest = new QuadTree(x,         y,         w / 2, h / 2);
    northEast = new QuadTree(x + w / 2, y,         w / 2, h / 2);
    southWest = new QuadTree(x,         y + h / 2, w / 2, h / 2);
    southEast = new QuadTree(x + w / 2, y + h / 2, w / 2, h / 2);
}
