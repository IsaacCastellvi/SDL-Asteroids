#pragma once
#include "scene.h"
#include <SDL2/SDL_ttf.h>

class GameScene : public scene
{
private:
	float asteroidSpawnTimer;
	float spawnAsteroidTime = 1.0f;

public:
	int spawnAmountForIteration = 3;
	void Start() override;
	void Update(float delta) override;
	void Render() override;
	void Clear() override;
	int score;
	TTF_Font* font = nullptr;

};


