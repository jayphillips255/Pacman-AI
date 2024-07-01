#include "EntityManager.h"
#include <iostream>


EntityManager::EntityManager() {
    entityIndex = ghostIndex = itemIndex = 0;
}

EntityManager::EntityManager(float height, float width) {
    entityIndex = ghostIndex = itemIndex = 0;
    this->height = height;
    this->width = width;
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
            ghosts[ghostIndex] = Ghost(info.st, info.fileName, xpos, ypos, height, width);
            entities[entityIndex++] = &ghosts[ghostIndex++];
            break;
        case EntityTypes::generalType::ITEM:
            items[itemIndex] = Item(info.st, info.fileName, xpos, ypos, height, width);
            entities[entityIndex++] = &items[itemIndex++];
            break;
        default:
            break;
    }
}

void EntityManager::updateEntities() {
    for (std::size_t i = 0; i < entityIndex; i++) {
        entities[i]->update();
    }
}

void EntityManager::renderEntities() {
    for (std::size_t i = 0; i < itemIndex; i++) {
        items[i].render();
    }
    pacman.render();
}
