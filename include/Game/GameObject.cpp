#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* fileName, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::loadTexture(fileName, ren);
    xpos = x;
    ypos = y;
}

void GameObject::update()
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

void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, NULL, &dstR);
}