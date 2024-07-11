#pragma once
#include "Agent.h"


class Ghost : public Agent {
    public:
        Ghost();
        Ghost(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        ~Ghost();
        void updateDirection() override;
        void update() override;
        void updatePosition() override;
        void resolveCollisions() override;
    private:
};
