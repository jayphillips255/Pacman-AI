#include <iostream>
#include "Game.h"
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
            yGridPos = (ypos / Game::tileWidth) + 1;
            ypos = yGridPos * Game::tileWidth;
            break;
        case Direction::DOWN:
            yGridPos = (ypos / Game::tileWidth);
            ypos = yGridPos * Game::tileWidth;
            break;
        case Direction::LEFT:
            xGridPos = (xpos / Game::tileWidth) + 1;
            xpos = xGridPos * Game::tileWidth;
            break;
        case Direction::RIGHT:
            xGridPos = (xpos / Game::tileWidth);
            xpos = xGridPos * Game::tileWidth;
            break;
        default:
            break;
    }
    direction = Direction::STOP;
}
