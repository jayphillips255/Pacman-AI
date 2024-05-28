#include <iostream>
#include <Game/Game.h>


// NOTE: This code is from the SDL2 tutorial: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
//       It's purpose is to test the project structure and verify a successful compilation and run
//       The video tutorial uses Visual Studio, but this project has been configured for VSCode

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White transparent background

    SDL_Surface* tempSurface = IMG_Load("assets/mario.png");
    SDL_Texture* playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);


    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000); // Display the window for 3 seconds

    return 0;
}