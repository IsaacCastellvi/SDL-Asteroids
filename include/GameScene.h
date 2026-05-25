#pragma once
#include "scene.h"
#include <SDL2/SDL_ttf.h>

class GameScene : public scene
{
private:

public:
	void Start() override;
	void Update(float delta) override;
	void Render() override;
	void Clear() override;
	int score;
	TTF_Font* font = nullptr;
};


