#include <iostream>
#include "Player.h"
#include "Game.h"


Player::Player() {}

Player::Player(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Agent(sType, path, x, y, w, h) {
        speed = 1.5f; // 1.5 pixels per frame
    }

Player::~Player() {}

void Player::updateDirection() {
    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
            case SDLK_UP:
                direction = Direction::UP;
                break;
            case SDLK_DOWN:
                direction = Direction::DOWN;
                break;
            case SDLK_LEFT:
                direction = Direction::LEFT;
                break;
            case SDLK_RIGHT:
                direction = Direction::RIGHT;
                break;
            default:
                break;
        }
    }
}

void Player::updatePosition() {
    updateDirection();
    switch (direction) {
        case Direction::UP:
            ypos -= speed;
            break;
        case Direction::DOWN:
            ypos += speed;
            break;
        case Direction::LEFT:
            xpos -= speed;
            break;
        case Direction::RIGHT:
            xpos += speed;
            break;
        default:
            break;
    }
}

void Player::update() {}

void Player::resolveCollisions() {
    for (std::size_t i = 0; i < collisions.size(); i++) {
        switch (collisions[i]->getSpecificType()) {
            case EntityTypes::specificType::WALL:
                resolveWallCollision();
                break;
            default:
                break;
        }
    }
    collisions.clear();
    dstR.x = static_cast<int>(xpos);
    dstR.y = static_cast<int>(ypos);
}
