#include "Agent.h"

Agent::Agent(const char* path, float s, float x, float y, float h, float w)
    : Entity(path, x, y, h, w) {
        speed = s;
}

Agent::~Agent() {}

bool Agent::atIntersection() {
    return true; // Needs implementation
}