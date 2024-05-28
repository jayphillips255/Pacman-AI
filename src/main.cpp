#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode

Game* game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();
    game->init("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}