#pragma once
#include "Entity.h"

class Agent : public Entity {
    public:
        Agent();
        Agent(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w);
        virtual ~Agent() override = 0;
        virtual void update() override = 0;
        void setSpeed(float s);
        bool atIntersection();
    private:
        enum class Direction {
            UP, DOWN, LEFT, RIGHT
        };
        Direction direction;
        float speed;
};
