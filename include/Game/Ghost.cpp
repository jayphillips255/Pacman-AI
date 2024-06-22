#include "Ghost.h"


Ghost::Ghost() {}

Ghost::Ghost(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w)
    : Agent(sType, path, x, y, h, w) {}

Ghost::~Ghost() {}

void Ghost::update() {}