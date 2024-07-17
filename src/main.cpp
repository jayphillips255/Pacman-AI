#include "../include/Game/CONSTANTS.h"
#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode

int main(int argc, char* argv[]) {
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart, frameTime;
    Game game("Pacman", int(GAME_WIDTH * TILE_WIDTH), int(GAME_HEIGHT * TILE_WIDTH), TILE_WIDTH, false);
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
