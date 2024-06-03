#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(const char* path, int x, int y)
{
    objTexture = TextureManager::loadTexture(path);
    dstR.x = x;
    dstR.y = y;
    dstR.h = dstR.w = 64;
}

Entity::~Entity()
{}

void Entity::update()
{
    dstR.x++;
    dstR.y++;
}

void Entity::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}
