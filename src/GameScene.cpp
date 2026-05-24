#include "GameScene.h"
#include "ship.h"

void GameScene::Start(){
    AddObject<ship>();
}

void GameScene::Update(float delta){

    for (gameObject* gm : SceneObjects)
    {
        gm->Update(delta);
    }
    
}

void GameScene::Render(){
    for (gameObject* gm : SceneObjects)
    {
        gm->Render();
    }
}
void GameScene::Clear(){
    for (gameObject* gm : SceneObjects)
    {
        delete gm;
    }
}