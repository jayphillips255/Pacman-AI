#include "EntityManager.h"
#include <iostream>


EntityManager::EntityManager() {
    entityIndex = ghostIndex = itemIndex = 0;
}

EntityManager::EntityManager(float width, float height) {
    entityIndex = ghostIndex = itemIndex = 0;
    this->width = width;
    this->height = height;
    quadTree = QuadTree(0.0f, 0.0f, width, height);
}

EntityManager::~EntityManager() {}

void EntityManager::addEntity(char c, float xpos, float ypos, float width, float height) {
    EntityTypes::entityInfo info = EntityTypes::entityTypes.at(c);
    switch (info.gt) {
        case EntityTypes::generalType::PLAYER:
            pacman = Player(info.st, info.fileName, xpos, ypos, width, height);
            entities[entityIndex] = &pacman;
            break;
        case EntityTypes::generalType::GHOST:
            ghosts[ghostIndex] = Ghost(info.st, info.fileName, xpos, ypos, width, height);
            entities[entityIndex] = &ghosts[ghostIndex++];
            break;
        case EntityTypes::generalType::ITEM:
            items[itemIndex] = Item(info.st, info.fileName, xpos, ypos, width, height);
            entities[entityIndex] = &items[itemIndex++];
            break;
        default:
            break;
    }
    Entity* tempPtr = entities[entityIndex++];
    quadTree.insertPoint(tempPtr->getX(), tempPtr->getY(), tempPtr);
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
