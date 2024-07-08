#include "QuadTree.h"


QuadTree::QuadTree() {
    entityIndex = 0;
    divided = false;
    northWest = nullptr;
    northEast = nullptr;
    southWest = nullptr;
    southEast = nullptr;
}

QuadTree::QuadTree(float x, float y, float width, float height) {
    entityIndex = 0;
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

bool QuadTree::outOfBounds(Entity* e) const {
    bool outBoundsX = (e->getx() < this->x) || (e->getx() + e->getw() > this->x + this->w);
    bool outBoundsY = (e->gety() < this->y) || (e->gety() + e->geth() > this->y + this->h);
    return outBoundsX || outBoundsY;
}

bool QuadTree::intersects(Entity* e) const {
    bool horizontalOverlap = (e->getx() + e->getw()) < this->x || e->getx() > (this->x + this->w);
    bool verticalOverlap = (e->gety() + e->geth()) < this->y || e->gety() > (this->y + this->h);
    return horizontalOverlap && verticalOverlap;
}

bool QuadTree::insertEntity(Entity* e) {
    if (outOfBounds(e)) {
        return false;
    }
    if (entityIndex < CAPACITY && !divided) {
        entities[entityIndex++] = e;
        return true;
    }
    if (!divided) {
       subdivide(); 
    }
    if (northWest->insertEntity(e)) return true;
    if (northEast->insertEntity(e)) return true;
    if (southWest->insertEntity(e)) return true;
    if (southEast->insertEntity(e)) return true;
    return false; // Should only reach this point if something went wrong
}

bool QuadTree::removeEntity(Entity* e) {
    for (std::size_t i = 0; i < entityIndex; i++) {
        if (entities[i] == e) {
            this->entityIndex--;
            return true;
        }
    }
    if (northWest->intersects(e)) return removeEntity(e);
    if (northEast->intersects(e)) return removeEntity(e);
    if (southWest->intersects(e)) return removeEntity(e);
    if (southEast->intersects(e)) return removeEntity(e);
    return false;
}

void QuadTree::checkCollision(Agent* agent) {
    for (std::size_t i = 0; i < this->entityIndex; i++) {
        if (agent->AABB(agent, entities[i])) {
            agent->updateCollisions(entities[i]);
        }
    }
    if (!this->divided) {
        return;
    }
    if (northWest->intersects(agent)) checkCollision(agent);
    if (northEast->intersects(agent)) checkCollision(agent);
    if (southEast->intersects(agent)) checkCollision(agent);
    if (southEast->intersects(agent)) checkCollision(agent);
}

void QuadTree::subdivide() {
    northWest = new QuadTree(x,         y,         w / 2, h / 2);
    northEast = new QuadTree(x + w / 2, y,         w / 2, h / 2);
    southWest = new QuadTree(x,         y + h / 2, w / 2, h / 2);
    southEast = new QuadTree(x + w / 2, y + h / 2, w / 2, h / 2);
    divided = true;
}
