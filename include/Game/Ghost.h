#pragma once
#include "Agent.h"


class Ghost : public Agent {
    public:
        Ghost();
        Ghost(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w);
        ~Ghost();
        void update() override;
    private:
};