#pragma once
#include <SDL2/SDL.h>
#include "SDLmath.h"
#include <vector>

//TODO spritesheet animation with rectangles later
struct SpriteAnimation {
public:
    float speed = 1.0f;

    SpriteAnimation() : index(0), timer(0.0f) {}
    void AddTexture(SDL_Texture* t) { textures.push_back(t); }
    SDL_Texture* GetTexture() { return textures[index]; }

    void Play(float deltaTime) {
        timer += deltaTime;
        if (timer >= 1.0f / speed) {
            index = (index + 1) % textures.size();
            timer = 0.0f;
        }
    }

private:
    std::vector<SDL_Texture*> textures;
    int index;
    float timer;
};


class gameObject {
public:
    virtual void Render() = 0;
    virtual void Update(float deltaTime) = 0;

    Vector2 position;
    SDL_Texture* texture = nullptr;

    //gameObject();
};