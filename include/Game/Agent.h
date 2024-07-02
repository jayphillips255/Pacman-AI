#pragma once
#include "Entity.h"


class Agent : public Entity {
    public:
        Agent();
        Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        virtual ~Agent() override = 0;
        virtual void update() override = 0;
        void setSpeed(float s);
        bool wallCollision();
        bool atIntersection();
    protected:
        float speed;
        enum class Direction {
            UP, DOWN, LEFT, RIGHT
        };
        Direction direction;
};
