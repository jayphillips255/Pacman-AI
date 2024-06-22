#include "Agent.h"


Agent::Agent() {};

Agent::Agent(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w)
    : Entity(sType, path, x, y, h, w) {}

Agent::~Agent() {}

void Agent::setSpeed(float s) {
    speed = s;
}

bool Agent::atIntersection() {
    return true; // Needs implementation
}
