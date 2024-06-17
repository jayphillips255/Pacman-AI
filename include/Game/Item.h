#pragma once
#include "Entity.h"


class Item : public Entity {
    public:
        Item(const char* path, float x, float y, int h, int w);
        ~Item();
        void update() override;
        
};