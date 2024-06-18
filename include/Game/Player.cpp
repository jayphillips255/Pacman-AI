#include "Player.h"


Player::Player() {}

Player::Player(const char* path, float s, float x, float y, float h, float w)
    : Agent(path, s, x, y, h, w) {}

Player::~Player() {}

void Player::update() {}
