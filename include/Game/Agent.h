#pragma once
#include "Entity.h"


constexpr int MAX_COLLISION = 12;

class Agent : public Entity {
    public:
        Agent();
        Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        virtual ~Agent() override = 0;
        virtual void update() override = 0;
        void setSpeed(float s);
        void updateCollisions(Entity* newCollision);
        void resetCollisions();
    protected:
        Entity* collisions[MAX_COLLISION];
        int collisionIndex;
        float speed;
        enum class Direction {
            UP, DOWN, LEFT, RIGHT
        };
        Direction direction;
};
