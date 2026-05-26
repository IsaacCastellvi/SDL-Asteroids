#include "scene.h"
#include <SDL2/SDL_ttf.h>


class MenuScene : public scene
{
private:
    void Start() override;
	void Update(float delta) override;
	void Render() override;
	void Clear() override;

    TTF_Font* titleFont = nullptr;
    TTF_Font* subFont   = nullptr;

    void RenderText(const char* text, TTF_Font* font, SDL_Color color, int y);
public:

};