#include <iostream>
#include "CONSTANTS.h"
#include "Game.h"
#include "Agent.h"


Agent::Agent() {}

Agent::Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Entity(sType, path, x, y, w, h) {}

Agent::~Agent() {}

void Agent::setSpeed(float s) {
    speed = s;
}

void Agent::updateCollisions(Entity* newCollision) {
    if (collisions.size() >= MAX_COLLISION) {
        std::cout << " Error: Max collision entities exceeded." << std::endl;
        return;
    }
    collisions.push_back(newCollision);
    return;
}

void Agent::resolveWallCollision() {
    switch (direction) {
        case Direction::UP:
            yGridPos = (ypos / TILE_WIDTH) + 1;
            ypos = yGridPos * TILE_WIDTH;
            break;
        case Direction::DOWN:
            yGridPos = (ypos / TILE_WIDTH);
            ypos = yGridPos * TILE_WIDTH;
            break;
        case Direction::LEFT:
            xGridPos = (xpos / TILE_WIDTH) + 1;
            xpos = xGridPos * TILE_WIDTH;
            break;
        case Direction::RIGHT:
            xGridPos = (xpos / TILE_WIDTH);
            xpos = xGridPos * TILE_WIDTH;
            break;
        default:
            break;
    }
    direction = Direction::STOP;
}
