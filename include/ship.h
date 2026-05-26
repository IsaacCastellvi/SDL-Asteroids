#include "gameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class ship : public gameObject {
public:
    void Render() override;
    void Update(float delta) override;

    int lives = 3;
    ship();

private:
    float angle = 0.0f;
    float rotationSpeed = 90.0f;
    float thrustSpeed = 80.0f;
};