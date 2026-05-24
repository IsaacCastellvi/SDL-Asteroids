#include "GameScene.h"
#include "ship.h"
#include "asteroid.h"
#include "time.h"

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
        SceneObjects[i]->Update(delta);
    }
}

void GameScene::Render(){
    for (gameObject* gm : SceneObjects)
    {
        gm->Render();
    }
}

void GameScene::Clear() {
    for (gameObject* gm : SceneObjects) delete gm;
    SceneObjects.clear();
}