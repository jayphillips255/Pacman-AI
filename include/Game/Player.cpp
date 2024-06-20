#include "Player.h"


Player::Player() {}

Player::Player(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w)
    : Agent(sType, path, x, y, h, w) {}

Player::~Player() {}

void Player::update() {}
