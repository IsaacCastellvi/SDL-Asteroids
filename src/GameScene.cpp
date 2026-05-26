#include "GameScene.h"
#include "ship.h"
#include "asteroid.h"
#include "time.h"
#include "bullet.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "SceneManager.h"

void GameScene::Start(){
    srand(time(nullptr)); 
    font = TTF_OpenFont("assets/CreatoDisplay-Regular.otf", 24);
    if (!font)
    {
        std::cout << "blyat";
    }
    
    AddObject<ship>();

    for (int i = 0; i < 3; i++) AddObject<asteroid>(LARGE);
    for (int i = 0; i < 3; i++) AddObject<asteroid>(MEDIUM);
    for (int i = 0; i < 3; i++) AddObject<asteroid>(SMALL);
}

void GameScene::Update(float delta){
    size_t count = SceneObjects.size();
    for (size_t i = 0; i < count; i++) {
        if(SceneObjects[i]->IsActive())SceneObjects[i]->Update(delta);
    }

    //bullet asteroid
    for (gameObject* obj : SceneObjects) {
        bullet* b = dynamic_cast<bullet*>(obj);
        if (!b || !b->IsActive()) continue;

        for (gameObject* other : SceneObjects) {
            asteroid* a = dynamic_cast<asteroid*>(other);
            if (!a || !a->IsActive()) continue;

            if (b->CollidesWith(a)) {
                b->SetActive(false);
                a->SetActive(false);
                if (a->GetSize() == AsteroidSize::LARGE)
                {
                    for (size_t i = 0; i < 2; i++){AddObject<asteroid>(MEDIUM,a->position);}
                }

                score += a->GetPoints();
                SDL_Log("Hit! +%d points, total: %d", a->GetPoints(), score);
            }
        }
    }

    // ship asteroid
    for (gameObject* obj : SceneObjects) {
        ship* s = dynamic_cast<ship*>(obj);
        if (!s || !s->IsActive()) continue;

        for (gameObject* other : SceneObjects) {
            asteroid* a = dynamic_cast<asteroid*>(other);
            if (!a || !a->IsActive()) continue;

            if (s->CollidesWith(a)) {
                s->lives--;
                //seg error even tho it exits?? Fix Change scene in the end of uddate will iterate deleted memory if not
                if (s->lives <= 0 ) {        
                    pendingTransition = true;
                    pendingScene = SceneIndex::MENU_SCENE;
                }

                
                SDL_Log("Ship hit!");
                
            }
        }
    }
    if (pendingTransition) {
        pendingTransition = false;
        SCENES.TransitionScene(pendingScene);
    }
}

void GameScene::Render(){
    for (gameObject* gm : SceneObjects)
    {
        if(gm->IsActive())gm->Render();
    }
    std::string text = "SCORE: " + std::to_string(score);
    SDL_Color white = { 255, 255, 255, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(GAME.GetRenderer(), surface);

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dst = { 10, 10, w, h };  // top left corner

    SDL_RenderCopy(GAME.GetRenderer(), texture, nullptr, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void GameScene::Clear() {
    for (gameObject* gm : SceneObjects) delete gm;
    SceneObjects.clear();
}