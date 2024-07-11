#include "Ghost.h"


Ghost::Ghost() {}

Ghost::Ghost(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Agent(sType, path, x, y, w, h) {}

Ghost::~Ghost() {}

void Ghost::updateDirection() {}

void Ghost::update() {}

void Ghost::updatePosition() {}

void Ghost::resolveCollisions() {}
