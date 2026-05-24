#pragma once
#include "gameObject.h"

class bullet : public gameObject {
public:
    bullet(Vector2 startPos, float angle);
    void Update(float delta) override;
    void Render() override;

private:
    float angle;
    float speed = 500.0f;
    Vector2 velocity;
};