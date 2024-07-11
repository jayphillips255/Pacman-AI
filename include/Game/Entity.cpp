#include "Entity.h"
#include "TextureManager.h"
#include <iostream>


Entity::Entity() {}

Entity::~Entity() {}

Entity::Entity(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h) {
    specificType = sType;
    tex = TextureManager::loadTexture(path);
    xpos = x;
    ypos = y;
    width = w;
    height = h;
    dstR.x = static_cast<int>(xpos);
    dstR.y = static_cast<int>(ypos);
    dstR.w = static_cast<int>(width);
    dstR.h = static_cast<int>(height);
}

bool Entity::AABB(Entity* e1, Entity* e2) {
    return e1->xpos < e2->xpos + e2->width  &&
           e1->xpos + e1->width > e2->xpos  &&
           e1->ypos < e2->ypos + e2->height &&
           e1->ypos + e1->height > e2->ypos;
}

void Entity::render() {
    SDL_RenderCopy(Game::renderer, tex, NULL, &dstR);
}

float Entity::getx() {
    return xpos;
}

float Entity::gety() {
    return ypos;
}

float Entity::getw() {
    return width;
}

float Entity::geth() {
    return height;
}

EntityTypes::specificType Entity::getSpecificType() {
    return specificType;
}
