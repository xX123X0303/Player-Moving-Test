#pragma once

struct GLFWwindow;

#include "Quad.h"

class Player
{
public:
	float x;
	float y;

	float speed;

	Player();

	void Update(GLFWwindow* window, float deltaTime);
	void Draw(Quad& quad);
};