#include "Entity.h"
#include "TextureManager.h"
/*
Entity::Entity()
{
    const char* p = "assets/mario.png";
    objTexture = TextureManager::loadTexture(p);
    srcR.x = srcR.y = 500;
    srcR.w = srcR.h = 500;
    dstR.x = dstR.y = 0;
    dstR.h = dstR.w = 64;
}
*/
Entity::Entity(const char* path, int x, int y)
{
    objTexture = TextureManager::loadTexture(path);
    srcR.x = srcR.y = 200;
    srcR.w = srcR.h = 200;
    dstR.x = dstR.y = 0;
    dstR.h = dstR.w = 0;
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
