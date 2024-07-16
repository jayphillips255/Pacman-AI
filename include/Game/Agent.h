#pragma once
#include <vector>
#include "Entity.h"


constexpr int MAX_COLLISION = 12;

class Agent : public Entity {
    public:
        Agent();
        Agent(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h);
        virtual ~Agent() override = 0;
        virtual void update() override = 0;
        virtual void updateDirection() = 0;
        virtual void updatePosition() = 0;
        void setSpeed(float s);
        void updateCollisions(Entity* newCollision);
        virtual void resolveCollisions() = 0;
    protected:
        void resolveWallCollision();
        //Entity* collisions[MAX_COLLISION];
        std::vector<Entity*> collisions;
        int collisionIndex;
        float speed;
        enum class Direction {
            UP, DOWN, LEFT, RIGHT, STOP
        };
        Direction direction;
};
