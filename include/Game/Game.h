#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {
    public:
        Game();
        ~Game();
        void init(const char* title, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        bool isRunning;
        SDL_Window* window;
};
