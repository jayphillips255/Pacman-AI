#include "EntityManager.h"


EntityManager::EntityManager() {
    entityIndex = ghostIndex = itemIndex = 0;
}

EntityManager::~EntityManager() {}

void EntityManager::addEntity(char c, float xpos, float ypos, float height, float width) {
    EntityTypes::entityInfo info = EntityTypes::entityTypes.at(c);
    switch (info.gt) {
        case EntityTypes::generalType::PLAYER:
            pacman = Player(info.st, info.fileName, xpos, ypos, height, width);
            entities[entityIndex++] = &pacman;
            break;
        case EntityTypes::generalType::GHOST:
            ghosts[ghostIndex++] = Ghost(info.st, info.fileName, xpos, ypos, height, width);
            entities[entityIndex++] = &ghosts[ghostIndex];
            break;
        case EntityTypes::generalType::ITEM:
            items[itemIndex++] = Item(info.st, info.fileName, xpos, ypos, height, width);
            entities[entityIndex++] = &items[itemIndex];
            break;
        default:
            break;
    }
}
