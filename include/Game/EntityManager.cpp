#include "CONSTANTS.h"
#include "EntityManager.h"
#include <iostream>


EntityManager::EntityManager() {
    entityIndex = agentIndex = ghostIndex = itemIndex = 0;
}

EntityManager::EntityManager(float width, float height) {
    entityIndex = agentIndex = ghostIndex = itemIndex = 0;
    this->width = width;
    this->height = height;
    quadTree = QuadTree(0.0f, 0.0f, width, height);
}

EntityManager::~EntityManager() {}

void EntityManager::addEntity(char c, int xGridPos, int yGridPos, float width, float height) {
    EntityTypes::entityInfo info = EntityTypes::entityTypes.at(c);
    switch (info.gt) {
        case EntityTypes::generalType::PLAYER:
            pacman = Player(info.st, info.fileName, xGridPos * TILE_WIDTH, yGridPos * TILE_WIDTH, width, height);
            entities[entityIndex] = agents[agentIndex++] = &pacman;
            break;
        case EntityTypes::generalType::GHOST:
            ghosts[ghostIndex] = Ghost(info.st, info.fileName, xGridPos * TILE_WIDTH, yGridPos * TILE_WIDTH, width, height);
            entities[entityIndex] = agents[agentIndex++] = &ghosts[ghostIndex++];
            break;
        case EntityTypes::generalType::ITEM:
            items[itemIndex] = Item(info.st, info.fileName, xGridPos * TILE_WIDTH, yGridPos * TILE_WIDTH, width, height);
            quadTree.insert(&(items[itemIndex])); // Only items will be in the QuadTree
            entities[entityIndex] = &items[itemIndex++];
            break;
        case EntityTypes::generalType::EMPTY:
            break;
        default:
            break;
    }
    updateWallMatrix(info.st, xGridPos, yGridPos);
    entityIndex++;
}

void EntityManager::updateEntities() {
    for (std::size_t i = 0; i < agentIndex; i++) {
        agents[i]->updatePosition();
    }
    for (std::size_t i = 0; i < agentIndex; i++) {
        quadTree.checkCollisions(agents[i]);
    }
    for (std::size_t i = 0; i < agentIndex; i++) {
        agents[i]->resolveCollisions();
    }
}

void EntityManager::renderEntities() {
    for (std::size_t i = 0; i < itemIndex; i++) {
        items[i].render();
    }
    for (std::size_t i = 0; i < ghostIndex; i++) {
        ghosts[i].render();
    }
    pacman.render();
}

// TODO: Finish this method
inline void EntityManager::updateWallMatrix(EntityTypes::specificType st, int xGrisPos, int yGridPos) {
    switch (st) {
        case EntityTypes::specificType::WALL:
            wallMatrix[xGrisPos][yGridPos] = true;
        default:
            break;
    }
}
