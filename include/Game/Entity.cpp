#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(const char* path, int x, int y) {
    objTexture = TextureManager::loadTexture(path);
    xpos = x;
    ypos = y;
    dstR.x = static_cast<int>(xpos);
    dstR.y = static_cast<int>(ypos);
    dstR.h = dstR.w = 48;
    speed = 1.5;
}

Entity::~Entity() {}

void Entity::update() {
    xpos += speed;
    dstR.x = static_cast<int>(xpos);
}

void Entity::render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}
