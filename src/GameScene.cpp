#include "GameScene.h"
#include "ship.h"
#include "asteroid.h"
#include "time.h"
#include "bullet.h"

void GameScene::Start(){
    srand(time(nullptr)); 

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
                score += a->GetPoints();
                SDL_Log(a->GetPoints(), score);
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
                SDL_Log("Ship hit!");
                
            }
        }
    }
}

void GameScene::Render(){
    for (gameObject* gm : SceneObjects)
    {
        if(gm->IsActive())gm->Render();
    }
}

void GameScene::Clear() {
    for (gameObject* gm : SceneObjects) delete gm;
    SceneObjects.clear();
}