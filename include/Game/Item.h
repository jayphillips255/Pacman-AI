#pragma once
#include "Entity.h"


class Item : public Entity {
    public:
        Item();
        Item(const char* path, float x, float y, float h, float w);
        ~Item();
        void update() override;
};