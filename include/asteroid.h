#pragma once
#include "gameObject.h"
#include "game.h"

enum AsteroidSize { LARGE, MEDIUM, SMALL };

class asteroid : public gameObject {
public:
    asteroid(AsteroidSize size);
    asteroid(AsteroidSize size,Vector2 pos);
    void Update(float delta) override;
    void Render() override;
    void Hit();

    int GetPoints() const { return points; }
    AsteroidSize GetSize() const { return size; }

    ~asteroid();

private:
    AsteroidSize size;
    Vector2 velocity;
    float rotationAngle = 0.0f;
    float rotationSpeed;
    int points;
    SDL_Rect src; 

    void InitBySize();
    Vector2 RandomEdgeSpawn();
};