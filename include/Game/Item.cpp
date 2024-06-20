#include "Item.h"


Item::Item() {};

Item::Item(EntityTypes::specificType sType, const char* path, float x, float y, float h, float w)
    : Entity(sType, path, x, y, h, w) {}

Item::~Item() {}

void Item::update() {}
