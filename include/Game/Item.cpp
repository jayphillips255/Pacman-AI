#include "Item.h"


Item::Item() {};

Item::Item(const char* path, float x, float y, float h, float w)
    : Entity(path, x, y, h, w) {}

Item::~Item() {}

void Item::update() {}
