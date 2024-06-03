#include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "Entity.h"



TileMap* map;

SDL_Renderer* Game::renderer = nullptr;

Entity* player;
Entity* enemy;

Entity myEntity("assets/mario.png", 0, 0);

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!..." << std::endl;
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    player = new Entity("assets/mario.png", 0, 0);
    enemy = new Entity("assets/goomba.png", 50, 50);
    map = new TileMap("assets/classicGame.txt", 3, 10, 64);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    player->update();
    enemy->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->render();
    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}