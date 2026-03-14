#include "Texture.h"

Texture::Texture(const char* image, GLenum texType)
{
	type = texType;

	int numColCh;
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	if (!bytes)
	{
		std::cout << "Failed to load texture" << std::endl;
		std::cout << "Reason" << stbi_failure_reason() << std::endl;
		ID = 0;
		return;
	}

	glGenTextures(1, &ID);
	glBindTexture(texType, ID);

	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	GLenum formatType;
	if (numColCh == 1) formatType = GL_RED;
	else if (numColCh == 3) formatType = GL_RGB;
	else if (numColCh == 4) formatType = GL_RGBA;
	else formatType = GL_RGB;

	glTexImage2D(texType, 0, formatType, widthImg, heightImg, 0, formatType, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(texType);

	stbi_image_free(bytes);
	glBindTexture(texType, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

int Texture::GetWidthImg() const
{
	return widthImg;
}

int Texture::GetHeightImg() const
{
	return heightImg;
}

bool Texture::isValid() const
{
	return ID != 0;
}


void Texture::TexUnit(Shader& shader, const char* uniform, GLint unit)
{
	GLuint texUnit = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUnit, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(type, ID);
}