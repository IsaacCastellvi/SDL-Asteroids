#include "ship.h"
#include "InputManager.h"
#include "game.h"

ship::ship() {
    texture = IMG_LoadTexture(GAME.GetRenderer(), "assets/lleida.jpeg");
    position = { 400, 300 };
}

void ship::Update(float delta) {
    if (IM.GetKey(SDLK_a, DOWN) || IM.GetKey(SDLK_a, HOLD))
        angle -= rotationSpeed * delta;
        position.setX(position.getX() + rotationSpeed * delta);


    if (IM.GetKey(SDLK_d, DOWN) || IM.GetKey(SDLK_d, HOLD))
        angle += rotationSpeed * delta;
        position.setY(position.getY() + rotationSpeed * delta);

    if (angle < 0)   angle += 360.0f;
    if (angle > 360) angle -= 360.0f;
}

void ship::Render() {
    SDL_SetRenderDrawColor(GAME.GetRenderer(), 255, 0, 0, 255);
    SDL_Rect debug = { (int)position.getX(), (int)position.getY(), 64, 64 };
    SDL_RenderFillRect(GAME.GetRenderer(), &debug);

    SDL_RenderCopyEx(GAME.GetRenderer(), texture, nullptr, &debug, angle, nullptr, SDL_FLIP_NONE);
}