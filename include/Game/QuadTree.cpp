#include <iostream>
#include "QuadTree.h"


QuadTree::QuadTree() {
    divided = false;
    northWest = nullptr;
    northEast = nullptr;
    southWest = nullptr;
    southEast = nullptr;
}

QuadTree::QuadTree(float x, float y, float width, float height) {
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

bool QuadTree::intersects(Entity* e) const {
    return e->getx() < this->x + this->w   &&
           e->getx() + e->getw() > this->x &&
           e->gety() < this->y + this->h   &&
           e->gety() + e->geth() > this->y;
}

bool QuadTree::insert(Entity* e) {
    if (!intersects(e)) {
        return false;
    }
    if ((entities.size() < MAX_CAPACITY) && !divided) {
        entities.push_back(e);
        return true;
    }
    if (!divided) {
       subdivide();
    }
    if (northWest->insert(e)) return true;
    if (northEast->insert(e)) return true;
    if (southWest->insert(e)) return true;
    if (southEast->insert(e)) return true;
    return false; // Should only reach this point if something went wrong
}

bool QuadTree::remove(Entity* e) {
    for (std::size_t i = 0; i < entities.size(); i++) {
        if (entities[i] == e) {
            entities.pop_back();
            break;
        }
    }
    if (northWest->intersects(e)) return northWest->remove(e);
    if (northEast->intersects(e)) return northEast->remove(e);
    if (southWest->intersects(e)) return southWest->remove(e);
    if (southEast->intersects(e)) return southEast->remove(e);
    return false;
}

void QuadTree::checkCollisions(Agent* agent) {
    for (std::size_t i = 0; i < entities.size(); i++) {
        if (agent->AABB(agent, entities[i])) {
            agent->updateCollisions(entities[i]);
        }
    }
    if (!divided) {
        return;
    }
    if (northWest->intersects(agent)) northWest->checkCollisions(agent);
    if (northEast->intersects(agent)) northEast->checkCollisions(agent);
    if (southWest->intersects(agent)) southWest->checkCollisions(agent);
    if (southEast->intersects(agent)) southEast->checkCollisions(agent);
}

void QuadTree::subdivide() {
    northWest = new QuadTree(x,         y,         w / 2, h / 2);
    northEast = new QuadTree(x + w / 2, y,         w / 2, h / 2);
    southWest = new QuadTree(x,         y + h / 2, w / 2, h / 2);
    southEast = new QuadTree(x + w / 2, y + h / 2, w / 2, h / 2);
    divided = true;
}
