#pragma once
#include "Agent.h"


class Player : public Agent {
    public:
        Player();
        Player(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w);
        ~Player();
        void update() override;
};
