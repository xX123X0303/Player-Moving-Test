#pragma once

#include <glad/glad.h>

class Quad
{
public:
	Quad();

	void Draw();
private:
	GLuint VBO, VAO, EBO;
};