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
    speed = 5;
    direction = STOP;
}

void Entity::update() {
    updatePosition();
    // Can add more things to update leter
}

inline void Entity::updatePosition() {
    float newx = xpos;
    float newy = ypos;
    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
            case SDLK_UP:
                direction = UP;
                newy = ypos - speed;
                break;
            case SDLK_DOWN:
                direction = DOWN;
                newy = ypos + speed;
                break;
            case SDLK_LEFT:
                direction = LEFT;
                newx = xpos - speed;
                break;
            case SDLK_RIGHT:
                direction = RIGHT;
                newx = xpos + speed;
                break;
            default:
                break;
        }
    }
    if (!wallColission()) {
        xpos = newx;
        ypos = newy;
        dstR.x = static_cast<int>(xpos);
        dstR.y = static_cast<int>(ypos);
    }
    // Otherwise, don't update position because we're facing a wall
}

bool Entity::wallColission() {
    // Identify the (x,y) grid position
    int xGridPos = static_cast<int>( xpos / Game::map->getTileWidth());
    int yGridPos = static_cast<int>( (ypos + 0.5) / Game::map->getTileWidth() );
    std::cout << "(" << xGridPos << ", " << yGridPos << ")" << std::endl;
    bool result = false;

    switch (direction) {
        case UP:
            if (Game::map->getType(xGridPos, yGridPos - 1) == EntityMap::entityType::WALL) {
                result = true;
                //std::cout << "WALL UP" << std::endl;
            }
            break;
        case DOWN:
            if (Game::map->getType(xGridPos, yGridPos + 1) == EntityMap::entityType::WALL) {
                result = true;
            }
            break;
        case LEFT:
            if (Game::map->getType(xGridPos - 1, yGridPos) == EntityMap::entityType::WALL) {
                result = true;
            }
            break;
        case RIGHT:
            if (Game::map->getType(xGridPos + 2, yGridPos) == EntityMap::entityType::WALL) {
                result = true;
            }
            break;
        default:
            break;
    }

    
    return result;
}


void Entity::render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstR);
}
