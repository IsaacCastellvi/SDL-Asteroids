#include <SDL2/SDL.h>
#include "InputManager.h"
#include "SDLmath.h"
#include <iostream>
#include "ship.h"
#include "game.h"
#include "SceneManager.h"
#include "scene.h"
#include "MenuScene.h"
#include "GameScene.h"


int main(int argc, char* argv[]) {
    if (!GAME.Init("Asteroids", 1000, 1000))
        return 1; 
    SCENES.AddScene<MenuScene>(SceneIndex::MENU_SCENE);
    SCENES.AddScene<GameScene>(SceneIndex::GAME_SCENE);

    SCENES.TransitionScene(SceneIndex::MENU_SCENE);

    //ship sp;
    Uint32 lastTime = SDL_GetTicks();
    while (!IM.GetQuit()) {

        //delta calcs from stackoverflow
        Uint32 now = SDL_GetTicks();
        float deltaTime = (float)(now - lastTime) / 1000.0f;
        lastTime = now;

        IM.Listen();

        SCENES.UpdateScene(deltaTime);

        SDL_SetRenderDrawColor(GAME.GetRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(GAME.GetRenderer());
        SCENES.RenderScene();
        SDL_RenderPresent(GAME.GetRenderer());
    }

    GAME.Shutdown();
    return 0;
}