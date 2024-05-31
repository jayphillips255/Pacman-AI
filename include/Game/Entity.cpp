#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(const char* path, int x, int y)
{
    objTexture = TextureManager::loadTexture(path);
    xpos = x;
    ypos = y;
}

void Entity::update()
{
    xpos++;
    ypos++;
    /*
    srcR.h = 64;
    srcR.w = 64;
    srcR.x = 0;
    srcR.y = 0;
    */
    dstR.x = xpos;
    dstR.y = xpos;
    dstR.w = 64;
    dstR.h = 64;
}

void Entity::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}