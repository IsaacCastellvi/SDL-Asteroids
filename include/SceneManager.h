#pragma once
#include <vector>
#include "scene.h"


#define SCENES SceneManager::Instance()

class SceneManager
{

public:

    static SceneManager& Instance(){
        static SceneManager instance;
        return instance;
    }

    template <typename T> void AddScene(SceneIndex index) {
        //assert suggested by ai (;
        static_assert(std::is_base_of<scene, T>::value, "T must inherit from scene");
        scenes[index] = new T();
    }
    void TransitionScene(SceneIndex indx){
        if (scenes[currentIndex] != nullptr) scenes[currentIndex]->Clear();
        currentIndex = indx;
        scenes[currentIndex]->Start();

    }

    void UpdateScene(float delta){
        scenes[currentIndex]->Update(delta);
    }
    void RenderScene(){
        scenes[currentIndex]->Render();
    }


private:
    SceneIndex currentIndex;
    scene* scenes[SceneIndex::SIZE];
    scene* current = nullptr;

};
