#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <map>


class Game {
    public:
        Game(const char* title, const int tw, int w, int h, bool fullscreen);
        ~Game();
        inline void startSDL(const char* title, const int tw, int w, int h, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        void addEntity();
        static SDL_Renderer* renderer;
        static SDL_Event event;
    private:
        int width;
        int height;
        int tileWidth;
        bool isRunning;
        SDL_Window* window;
        std::vector<Entity*> entities;
};
