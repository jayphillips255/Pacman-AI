#include "Item.h"


Item::Item() {};

Item::Item(EntityTypes::specificType sType, const char* path, float x, float y, float w, float h)
    : Entity(sType, path, x, y, w, h) {}

Item::~Item() {}

void Item::update() {}
