#include "Player.h"
#include "Game.h"


Player::Player() {}

Player::Player(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Agent(sType, path, x, y, w, h) {
        speed = 1.5f; // 1.5 pixels per frame
    }

Player::~Player() {}

void Player::update() {
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
    if (wallCollision()) {
        // TODO
    }
}
