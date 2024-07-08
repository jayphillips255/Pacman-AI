#include <iostream>
#include "Agent.h"


Agent::Agent() {
    collisionIndex = 0;
};

Agent::Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Entity(sType, path, x, y, w, h) {
        collisionIndex = 0;
    }

Agent::~Agent() {}

void Agent::setSpeed(float s) {
    speed = s;
}

void Agent::updateCollisions(Entity* newCollision) {
    if (collisionIndex >= MAX_COLLISION) {
        std::cout << " Error: Max collision entities exceeded." << std::endl;
        return;
    }
    collisions[collisionIndex++] = newCollision;
}

void Agent::resetCollisions() {
    collisionIndex = 0;
}
