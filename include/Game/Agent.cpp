#include "Agent.h"


Agent::Agent() {};

Agent::Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Entity(sType, path, x, y, w, h) {}

Agent::~Agent() {}

void Agent::setSpeed(float s) {
    speed = s;
}

bool Agent::wallCollision() {
    return true; // Needs implemtation
}

bool Agent::atIntersection() {
    return true; // Needs implementation
}
