#pragma once
#include <SDL2/SDL.h>
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
        int loadMap(const char* mapFile);
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
