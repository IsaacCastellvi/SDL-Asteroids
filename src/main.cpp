#include <SDL2/SDL.h>
#include "InputManager.h"
#include "SDLmath.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Asteroids",   // title
        1200,1200,
        1000,1000,
        0              // flags
    );

    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0,SDL_RENDERER_TARGETTEXTURE);

    if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool running = true;
    SDL_Event event;

    Vector2 vector(3,3);

    while (running) {
        IM.Listen();

        if (IM.GetLeftClick()){
            SDL_Quit();   
        }
        
        std::cout << vector.getX() << vector.getY();


        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 125, 180, 125, 255);
        SDL_RenderClear(renderer);

        // Present
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}