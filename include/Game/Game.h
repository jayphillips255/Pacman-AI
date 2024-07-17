#pragma once
#include <SDL2/SDL.h>
#include "EntityManager.h"


class Game {
    public:
        Game(const char* title, int width, int height, float tileWidth, bool fullscreen);
        ~Game();
        inline void startSDL(const char* title, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        void loadMap(const char* mapFile);
        static SDL_Renderer* renderer;
        static SDL_Event event;
        static int error;
    private:
        float tileWidth;
        bool isRunning;
        SDL_Window* window;
        EntityManager entityManager;
};
