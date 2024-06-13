#include "Game.h"
#include "TextureManager.h"
#include "Entity.h"


SDL_Renderer* Game::renderer = nullptr;
Entity* background;
Entity* player;
SDL_Event Game::event; // Allocate memory for storing events

Game::Game(const char* title, const int tw, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!..." << std::endl;
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    map = new EntityMap("assets/board.txt", 32, 28, tw);
    background = new Entity("assets/background.png", 0, 0, tw*32, tw*28);
    player = new Entity("assets/pacman.png", tw*13 + tw/12, tw*23 + tw*7/12, tw*2, tw*2);
}

Game::~Game() {
    delete player;
    delete background;
    delete map;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

void Game::handleEvents() {
    // event is a static member of Game, so it can be acessed when the gamestate updates each frame
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
}

void Game::update() {
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    background->render();
    map->render();
    player->render();
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}
