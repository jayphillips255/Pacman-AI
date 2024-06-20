#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include "EntityManager.h"


class Game {
    public:
        Game(const char* title, const float tw, int w, int h, bool fullscreen);
        ~Game();
        inline void startSDL(const char* title, const int tw, int w, int h, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        void loadMap(const char* mapFile);
        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        int width;
        int height;
        float tileWidth;
        bool isRunning;
        SDL_Window* window;
        EntityManager entityManager;
};
