#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>


class EntityMap {
    public:
        EntityMap();
        EntityMap(const char* path, int r, int c, int tw);
        ~EntityMap();
        enum entityType {
            EMPTY, WALL, DOOR, FOOD, PELLET
        };
        entityType getType(int x, int y);
        void setType(int x, int y, entityType type);
        void render();
        int getTileWidth();
    private:
        int rows;
        int cols;
        int tileWidth;
        SDL_Rect dstR;
        std::map<entityType, SDL_Texture*> textureMap;
        entityType** tileMap;
        inline void allocateMap();
        inline void deallocateMap();
        void updateTile(char& c, std::size_t& i, std::size_t& j);
};
