#pragma once
#include "Agent.h"


class Player : public Agent {
    public:
        Player();
        Player(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        ~Player();
        void updateDirection() override;
        void updatePosition() override;
        void update() override;
        void resolveCollisions() override;
};
