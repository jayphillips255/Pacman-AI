#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode



int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart; // Should be this instead of unsigned int for portability reasons
    int frameTime;

    Game game;
    game.init("Pacman", 672, 744, false);
    while (game.running())
    {
        frameStart = SDL_GetTicks(); // Number of milliseconds since SDL initialization

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart; // Calculate time to produce the new frame
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
