#pragma once
#include <vector>
#include "gameObject.h"

enum SceneIndex{
    MENU_SCENE,
    GAME_SCENE,
    SIZE,
};


class scene
{
private:
    
public:


    SceneIndex pendingScene;
    bool pendingTransition;

    template<typename T, typename... Args>
    //multiple args source https://stackoverflow.com/questions/19923353/multiple-typename-arguments-in-c-template-variadic-templates
    void AddObject(Args&&... args) {
        static_assert(std::is_base_of<gameObject, T>::value, "T must inherit from gameObject");
        SceneObjects.push_back(new T(std::forward<Args>(args)...));
    }
    std::vector<gameObject*> SceneObjects;
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
    virtual void Start() = 0;
    virtual void Clear() = 0;
    //scene();
    //~scene();
};
