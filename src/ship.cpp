#include "ship.h"
#include "InputManager.h"
#include "game.h"
#include "SceneManager.h"
#include "bullet.h"

ship::ship() {
    texture = IMG_LoadTexture(GAME.GetRenderer(), "assets/ship.png");
    position = { 400, 300 };
    
}

void ship::Update(float delta) {
    if (IM.GetKey(SDLK_a, DOWN) || IM.GetKey(SDLK_a, HOLD)) {
        angle -= rotationSpeed * delta;
    }

    if (IM.GetKey(SDLK_d, DOWN) || IM.GetKey(SDLK_d, HOLD)) {
        angle += rotationSpeed * delta;
    }
    
    if (angle < 0)   angle += 360.0f;
    if (angle > 360) angle -= 360.0f;

    if (IM.GetKey(SDLK_w, DOWN) || IM.GetKey(SDLK_w, HOLD)) {
        float rad = (angle - 90.0f) * M_PI / 180.0f;
        float dx = cos(rad) * thrustSpeed * delta;
        float dy = sin(rad) * thrustSpeed * delta;

        position.setX( dx + position.getX());
        position.setY(dy + position.getY());
    }
    if (IM.GetKey(SDLK_SPACE, DOWN)) {
        // Spawn at ship center
        Vector2 spawnPos = { position.getX() + 29, position.getY() + 29 };
        if (SCENES.GetCurrentScene() == nullptr){SDL_Log(0);  SDL_Quit();}        
        SCENES.GetCurrentScene()->AddObject<bullet>(spawnPos, angle);
    }
    



}

void ship::Render() {
    SDL_SetRenderDrawColor(GAME.GetRenderer(), 255, 0, 0, 255);
    SDL_Rect debug = { (int)position.getX(), (int)position.getY(), 64, 64 };
    SDL_RenderFillRect(GAME.GetRenderer(), &debug);

    SDL_RenderCopyEx(GAME.GetRenderer(), texture, nullptr, &debug, angle, nullptr, SDL_FLIP_NONE);
}