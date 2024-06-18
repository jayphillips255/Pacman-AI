#pragma once
#include "Entity.h"

class Agent : public Entity {
    public:
        Agent();
        Agent(const char* path, float s, float x, float y, float h, float w);
        virtual ~Agent() override = 0;
        virtual void update() override = 0;
        bool atIntersection();
    private:
        enum class Direction {
            UP, DOWN, LEFT, RIGHT
        };
        Direction direction;
        float speed;
};
