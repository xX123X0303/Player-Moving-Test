#pragma once

#include <glad/glad.h>
#include <stb_image.h>

#include "Shader.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;

	int widthImg, heightImg;

	Texture(const char* image, GLenum texType);
	~Texture();

	bool isValid() const;

	int GetWidthImg() const;
	int GetHeightImg() const;

	void TexUnit(Shader& shader, const char* uniform, GLint unit);
	void Bind();
};