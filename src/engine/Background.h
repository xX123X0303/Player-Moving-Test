#pragma once

struct GLFWwindow;

#include "Texture.h"
#include "Quad.h"
#include "Shader.h"

class Background
{
public:
	Background(GLFWwindow* window);

	void Draw(Quad& quad, Shader& shader);
private:
	int WinWidth;
	int WinHeight;
	Texture* texture = nullptr;
};