#pragma once
#include "gameObject.h"
#include "game.h"

enum AsteroidSize { LARGE, MEDIUM, SMALL };

class asteroid : public gameObject {
public:
    asteroid(AsteroidSize size);
    void Update(float delta) override;
    void Render() override;

    int GetPoints() const { return points; }
    AsteroidSize GetSize() const { return size; }

private:
    AsteroidSize size;
    Vector2 velocity;
    float rotationAngle = 0.0f;
    float rotationSpeed;
    int points;
    int radius;

    void InitBySize();
    Vector2 RandomEdgeSpawn();
};