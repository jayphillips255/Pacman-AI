#include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "Entity.h"


const int tw = 24; // Tile Width

SDL_Renderer* Game::renderer = nullptr;
TileMap* map;
Entity* player;
SDL_Event Game::event; // Allocate memory for storing events

Game::Game() {}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

void Game::init(const char* title, int width, int height, bool fullscreen) {
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
    map = new TileMap("assets/classicGame.txt", 31, 28, tw);
    player = new Entity("assets/pacman.png", float(tw*13 + tw/12), float(tw*22 + tw*7/12));
}

void Game::handleEvents() {
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
    map->render();
    player->render();
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}
