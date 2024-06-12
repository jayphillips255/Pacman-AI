#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>


class EntityMap {
    public:
        EntityMap();
        EntityMap(const char* path, int r, int c, int tw);
        ~EntityMap();
        void render();
    private:
        inline void allocateMap();
        inline void deallocateMap();
        void updateTile(char& c, std::size_t& i, std::size_t& j);
        int rows;
        int cols;
        int tileWidth;
        SDL_Rect dstR;
        enum entityType {
            EMPTY, WALL, DOOR, FOOD, PELLET
        };
        std::map<entityType, SDL_Texture*> textureMap;
        entityType** tileMap;
};
