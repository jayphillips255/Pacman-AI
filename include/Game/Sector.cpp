#include "Sector.h"


Sector::Sector() {
    entityIndex = 0;
}

Sector::~Sector() {}

void Sector::addEntity(Entity* ePtr) {
    sectorEntities[entityIndex++] = ePtr;
}
