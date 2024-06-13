#include "Entity.h"
#include "TextureManager.h"


Entity::~Entity() {}

Entity::Entity(const char* path, float x, float y, int height, int width) {
    objTexture = TextureManager::loadTexture(path);
    xpos = x;
    ypos = y;
    dstR.x = static_cast<int>(xpos);
    dstR.y = static_cast<int>(ypos);
    dstR.h = height;
    dstR.w = width;
    speed = 1.5;
}

void Entity::update() {
    updatePosition();
    xpos += speed;
    dstR.x = static_cast<int>(xpos);
}

inline void Entity::updatePosition() {
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
            // Direction is same as before
            break;
    }
    if (!wallColission() || direction != STOP) {
        // Advance in the direction
    }
}

bool Entity::wallColission() {
    // Identify the (x,y) grid position
    int xGridPos = static_cast<int>(xpos / Game::map->getTileWidth());
    int yGridPos = static_cast<int>(ypos / Game::map->getTileWidth());
    bool result = false;
    switch (direction) {
        case UP:
            if (Game::map->getType(xGridPos, yGridPos - 2) == EntityMap::entityType::WALL)
                result = true;
            break;
        case DOWN:
            if (Game::map->getType(xGridPos, yGridPos + 2) == EntityMap::entityType::WALL)
                result = true;
            break;
        case LEFT:
            if (Game::map->getType(xGridPos - 2, yGridPos) == EntityMap::entityType::WALL)
                result = true;
            break;
        case RIGHT:
            if (Game::map->getType(xGridPos + 2, yGridPos) == EntityMap::entityType::WALL)
                result = true;
            break;
        default:
            break;
    }
    return result;
}


void Entity::render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}
