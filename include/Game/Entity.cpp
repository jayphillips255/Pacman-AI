#include "Entity.h"
#include "TextureManager.h"


Entity::Entity() {}

Entity::Entity(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w) {
    specificType = sType;
    tex = TextureManager::loadTexture(path);
    xpos = x;
    ypos = y;
    height = h;
    width = w;
    dstR.x = static_cast<int>(xpos);
    dstR.y = static_cast<int>(ypos);
    dstR.h = static_cast<int>(height);
    dstR.w = static_cast<int>(width);
}

void Entity::render() {
    SDL_RenderCopy(Game::renderer, tex, NULL, &dstR);
}
