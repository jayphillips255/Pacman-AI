#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode



int main(int argc, char* argv[]) {
    const int width = 28, height = 31; // These are the height and width in number of game tiles
    const int tw = 24; // Tile Width
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart, frameTime;

    Game game("Pacman", tw, width, height, false);
    while (game.running()) {
        if (game.error) {
            return 1;
        }
        frameStart = SDL_GetTicks(); // Number of milliseconds since SDL initialization

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart; // Calculate time to produce the new frame
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
