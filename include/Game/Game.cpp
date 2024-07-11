#include <iostream>
#include <fstream>
#include "Game.h"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event; // For updating the game state
int Game::error;
float Game::tileWidth;

Game::Game(const char* title, const float tw, int w, int h, bool fullscreen) {
    error = 0;
    tileWidth = tw;
    width = w;
    height = h;
    entityManager = EntityManager(float(w * tw), float(h * tw));
    startSDL(title, tw, w, h, fullscreen);
    loadMap("assets/board.txt");
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

inline void Game::startSDL(const char* title, const int tw, int w, int h, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!..." << std::endl;
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w * tw, h * tw, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0,0,0,0);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    // event is a static member of Game, so it can be acessed when the gamestate updates each frame
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
}

void Game::update() {
    entityManager.updateEntities();
}

void Game::render() {
    SDL_RenderClear(renderer);
    entityManager.renderEntities();
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}

void Game::loadMap(const char* mapFile) {
    float x = 0.0f;
    float y = 0.0f;
    std::string line;
    std::ifstream fileBridge(mapFile);
    if (!fileBridge) {
        std::cerr << "Error opening file." << std::endl;
    }
    while (std::getline(fileBridge, line)) {
        x = 0.0f;
        for (std::size_t i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                entityManager.addEntity(line[i], x, y, tileWidth, tileWidth);
            }
            x += tileWidth;
        }
        y += tileWidth;
    }
    fileBridge.close();
}
