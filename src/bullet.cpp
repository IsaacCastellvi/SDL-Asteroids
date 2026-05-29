#include "bullet.h"
#include "game.h"

bullet::bullet(Vector2 startPos, float angle) : angle(angle) {
    position = startPos;

    float rad = (angle - 90.0f) * M_PI / 180.0f;
    velocity.setX(cos(rad) * speed);
    velocity.setY(sin(rad) * speed);

    texture = IMG_LoadTexture(GAME.GetRenderer(), "assets/asteroids_spritesheet.png");
}

void bullet::Update(float delta) {
    position.setX(position.getX() + velocity.getX() * delta);
    position.setY(position.getY() + velocity.getY() * delta);

    /*hardcoded screen
    if (position.x < 0 || position.x > 1000 ||
        position.y < 0 || position.y > 1000)
        */
}

void bullet::Render() {
    SDL_Rect src = { 32, 32, 8,8 };  
    SDL_Rect dst = { (int)position.getX(), (int)position.getY(), 8, 8 };
    SDL_Point center = { 32, 32 }; 
    SDL_RenderCopyEx(GAME.GetRenderer(), texture, &src, &dst, angle, &center, SDL_FLIP_NONE);
}