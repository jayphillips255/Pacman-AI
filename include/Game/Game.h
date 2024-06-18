#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Item.h"


constexpr int MAX_ENTITIES = 100;
constexpr unsigned short MAX_ITEMS = 500;
constexpr int MAX_GHOST = 4;

class Game {
    public:
        Game(const char* title, const int tw, int w, int h, bool fullscreen);
        ~Game();
        inline void startSDL(const char* title, const int tw, int w, int h, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        void loadMap(const char* mapFile);
        void addEntity(Entity* e);
        void addEntity(char &c);
        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        int width;
        int height;
        int tileWidth;
        bool isRunning;
        SDL_Window* window;
        int numEntities;
        Player pacman;
        Item items[MAX_ITEMS];
        Entity* entities[MAX_ENTITIES];
};
