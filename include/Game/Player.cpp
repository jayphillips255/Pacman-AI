#include "Player.h"
#include "Game.h"


Player::Player() {}

Player::Player(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w)
    : Agent(sType, path, x, y, h, w) {
        speed = 1.5; // 1.5 pixels per frame
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
