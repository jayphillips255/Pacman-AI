#include <iostream>
#include "TextureManager.h"


SDL_Texture* TextureManager::loadTexture(const char* fileName) {
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    if (!tmpSurface) {
        std::cerr << "Failed to load surface: " << SDL_GetError() << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}
