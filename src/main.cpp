
#include <SDL2/SDL.h>  // or <SDL2/SDL.h> if using SDL2

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Asteroids",   // title
        800, 600,
        300,300,
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

    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDLK_ESCAPE) running = false;
            if (event.type == SDLK_DOWN)
                if (event.key.type == SDLK_ESCAPE) running = false;
            if (event.type == SDL_QUIT){
                SDL_Quit();
            }
            
        }

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