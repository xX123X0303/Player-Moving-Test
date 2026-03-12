#pragma once
#include "glm/glm.hpp"
#include "Quad.h"

class Player
{
public:
	float x;
	float y;

	float speed;

	Player();

	void Update(float deltaTime);
	void Draw(Quad& quad);
};