#pragma once
#include "Agent.h"


class Ghost : public Agent {
    public:
        Ghost();
        Ghost(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        ~Ghost();
        void update() override;
    private:
};