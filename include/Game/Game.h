#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TileMap.h"


class Game {
    public:
        Game(const char* title, const int tw, int width, int height, bool fullscreen);
        ~Game();
        void handleEvents();
        void update();
        void render();
        bool running();
        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        bool isRunning;
        TileMap* map;
        SDL_Window* window;
};
