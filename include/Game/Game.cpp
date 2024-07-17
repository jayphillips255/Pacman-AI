#include <iostream>
#include <fstream>
#include "Game.h"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event; // For updating the game state
int Game::error = 0;

Game::Game(const char* title, int width, int height, float tileWidth, bool fullscreen) {
    this->tileWidth = tileWidth;
    entityManager = EntityManager(float(width), float(height));
    startSDL(title, width, height, fullscreen);
    loadMap("assets/board.txt");
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

inline void Game::startSDL(const char* title, int width, int height, bool fullscreen) {
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
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
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
    int xGridPos = 0, yGridPos = 0;
    std::string line;
    std::ifstream fileBridge(mapFile);
    if (!fileBridge) {
        std::cerr << "Error opening file." << std::endl;
    }
    while (std::getline(fileBridge, line)) {
        xGridPos = 0;
        for (std::size_t i = 0; i < line.size(); i++) {
            entityManager.addEntity(line[i], xGridPos, yGridPos, tileWidth, tileWidth);
            xGridPos++;
        }
        yGridPos++;
    }
    fileBridge.close();
}
