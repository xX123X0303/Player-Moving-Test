#pragma once

struct GLFWwindow;

#include "Quad.h"
#include "Shader.h"
#include "Texture.h"

class Player
{
public:
	Player(GLFWwindow* window);

	float x = 0.0f;
	float y = 0.0f;

	int WinWidth, WinHeight;
	float ImgWidth, ImgHeight;

	float speed = 0.8f;
	float rotation = 0.0f;

	void Update(GLFWwindow* window, float deltaTime);
	void Draw(Quad& quad, Shader& shader);

private:
	Texture* texture = nullptr;
};