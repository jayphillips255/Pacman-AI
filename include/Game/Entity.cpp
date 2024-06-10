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
    updateDirection();
    xpos += speed;
    dstR.x = static_cast<int>(xpos);
}

void Entity::updateDirection() {
    switch (Game::event.key.keysym.sym) {
        case SDLK_UP:
            direction = UP;
            break;
        case SDLK_DOWN:
            direction = DOWN;
            break;
        case SDLK_LEFT:
            direction = LEFT;
            break;
        case SDLK_RIGHT:
            direction = RIGHT;
            break;
        default:
            break;
    }
}

void Entity::updatePosition() {
    
}

void Entity::render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}
