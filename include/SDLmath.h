#pragma once


class Vector2{

    public:

    Vector2(float x, float y) : x(x), y(y) {}
    float getX() { return x; }
    float getY() { return y; }

    void setX(float x) { x = x; }
    void setY(float y) { y = y; }

    Vector2 operator+(const Vector2 &v2) const {
    return Vector2(x+v2.x, y+v2.y);
    }

    Vector2 operator-(const Vector2 &v2) const {
    return Vector2(x-v2.x, y-v2.y);
    }
    private:
    int x;
    int y;
};