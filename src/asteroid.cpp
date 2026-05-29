#include "asteroid.h"
#include <cstdlib>
#include <cmath>

asteroid::asteroid(AsteroidSize size) : size(size) {
    InitBySize();
    position = RandomEdgeSpawn();

    // Random direction toward center
    float angle = ((rand() % 360) * M_PI / 180.0f);
    float speed = 50.0f + rand() % 100;
    velocity.setX(cos(angle) * speed);
    velocity.setY(sin(angle) * speed);

    rotationSpeed = 20.0f + rand() % 60;
}
asteroid::asteroid(AsteroidSize size,Vector2 pos) : size(size) {
    InitBySize();

    position = pos;
    // Random direction toward center
    float angle = ((rand() % 360) * M_PI / 180.0f);
    float speed = 50.0f + rand() % 100;
    velocity.setX(cos(angle) * speed);
    velocity.setY(sin(angle) * speed);

    rotationSpeed = 20.0f + rand() % 60;
}
//migth refactor
void asteroid::InitBySize() {
    texture = IMG_LoadTexture(GAME.GetRenderer(), "assets/asteroids_spritesheet.png");
    switch (size) {
        case LARGE:
            points = 20;
            radius = 64;
            //weird placements
            src = { 160, 0, 96, 96 };
            break;
        case MEDIUM:
            points = 30;
            radius = 32;
            src = { 78, 0, 50, 50 };
            break;
        case SMALL:
            points = 50;
            radius = 16;
            src = { 41, 3, 37, 36 };
            break;
    }
}
Vector2 asteroid::RandomEdgeSpawn() {
    //hardcoded
    int screenW = 1000;
    int screenH = 1000;
    int side = rand() % 4;

    switch (side) {
        case 0: return { (float)(rand() % screenW), 0.0f };           
        case 1: return { (float)(rand() % screenW), (float)screenH }; 
        case 2: return { 0.0f, (float)(rand() % screenH) };           
        default: return { (float)screenW, (float)(rand() % screenH) };
    }
}

void asteroid::Update(float delta) {
    position.setX(position.getX() + velocity.getX() * delta);
    position.setY(position.getY() + velocity.getY() * delta);

    rotationAngle += rotationSpeed * delta;
    if (rotationAngle > 360) rotationAngle -= 360.0f;

    //bounds
    if (position.getX() < -radius)  position.setX(1000 + radius);
    if (position.getX() > 1000 + radius) position.setX(-radius);
    if (position.getY() < -radius)  position.setY(1000 + radius);
    if (position.getY() > 1000 + radius) position.setY(-radius);
}

void asteroid::Render() {

    SDL_Rect dst = {
        (int)position.getX() - radius,
        (int)position.getY() - radius,
        radius * 2,
        radius * 2
    };

    SDL_Point center = { radius, radius };

    SDL_RenderCopyEx(GAME.GetRenderer(), texture, &src, &dst, rotationAngle, &center, SDL_FLIP_NONE);
}

void asteroid::Hit(){



}

asteroid::~asteroid(){
    


}
