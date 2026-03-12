#pragma once
#include "glm/glm.hpp"
#include "Quad.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Player
{
public:
	float x;
	float y;

	float speed;

	Player();

	void Update(float deltaTime);
	void Draw(GLFWwindow* window, Quad& quad);
};