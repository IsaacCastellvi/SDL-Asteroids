#include "bullet.h"
#include "game.h"

bullet::bullet(Vector2 startPos, float angle) : angle(angle) {
    position = startPos;

    float rad = (angle - 90.0f) * M_PI / 180.0f;
    velocity.setX(cos(rad) * speed);
    velocity.setY(sin(rad) * speed);
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
    SDL_SetRenderDrawColor(GAME.GetRenderer(), 255, 255, 0, 255);
    SDL_Rect rect = { (int)position.getX(), (int)position.getY(), 8, 8 };
    SDL_RenderFillRect(GAME.GetRenderer(), &rect);
}