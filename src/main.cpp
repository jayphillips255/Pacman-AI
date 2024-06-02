#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode

Game* game = nullptr;

int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Pacman", 800, 640, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks(); // Number of ms since SDL initialization

        game->handleEvents();
//        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
}
