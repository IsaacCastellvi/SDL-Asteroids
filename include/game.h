#pragma once
#include <vector>
#include "scene.h"
#include "GameScene.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>

//cant autocomplete static properties on other files idk why
#define GAME Game::Instance()

class Game {
public:

    public:

    int LatestScore;

    static Game& Instance() {
        static Game instance;
        return instance;
    }

    SDL_Renderer* GetRenderer() { return renderer; }
    SDL_Window*   GetWindow()   { return window; }
    int GetWidth()  { return width; }
    int GetHeight() { return height; }

    void SafeScore(int score){
        std::ofstream file("assets/data/Highscores.csv");

        LatestScore = score;
        std::string str;
        if (file.is_open())
        {
            file << "name," << std::to_string(score);
        }
        
    }

    bool Init(const char* title, int w, int h) {    
        //GameScenes[SceneIndex::GameScene] = new GameScene();
    
        width = w;
        height = h;

        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init(); 

        window = SDL_CreateWindow(title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height, 0);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        //nullptr = false
        return window && renderer;
    }

    void Shutdown() {
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        //i think it wont terminate the full proces
        SDL_Quit();
    }

private:
    Game() : renderer(nullptr), window(nullptr), width(0), height(0) {}
    SDL_Renderer* renderer;
    SDL_Window*   window;
    int width, height;
};