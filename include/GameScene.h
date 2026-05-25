#pragma once
#include "scene.h"

class GameScene : public scene
{
private:

public:
	void Start() override;
	void Update(float delta) override;
	void Render() override;
	void Clear() override;
	int score;
};


