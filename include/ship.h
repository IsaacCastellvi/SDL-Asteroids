#include "gameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class ship : public gameObject {
public:
    void Render() override;
    void Update(float delta) override;

    ship();

private:
    float angle = 0.0f;
    float rotationSpeed = 180.0f;
};