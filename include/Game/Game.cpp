#include "Game.h"
#include "TextureManager.h"
#include "TileTypes.h"
#include "Entity.h"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event; // Static member for updating the game state

Game::Game(const char* title, const int tw, int w, int h, bool fullscreen) {
    startSDL(title, tw, w, h, fullscreen);
    tileWidth = tw;
    width = w;
    height = h;
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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}

void Game::loadMap(const char* mapFile) {
    std::string line;
    std::ifstream fileBridge;
    fileBridge.open(mapFile);
    while (std::getline(fileBridge, line)) {
        for (std::size_t i = 0; i < line.size(); i++) {
            addEntity(line[i]);
        }
    }
}

void Game::addEntity(Entity* e) {
    
}

void Game::addEntity(char &c) {
    
}
