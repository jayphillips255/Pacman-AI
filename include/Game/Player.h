#pragma once
#include "Agent.h"


class Player : public Agent {
    public:
        Player(const char* path, float s, float x, float y, float h, float w);
        ~Player();
        void update() override;
    private:
        
};
