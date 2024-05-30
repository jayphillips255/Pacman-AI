#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect srcR, SDL_Rect dstR)
{
    SDL_RenderCopy(Game::renderer, tex, NULL, &dstR); // &srcR
}
