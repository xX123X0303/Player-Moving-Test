#include "Background.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Background::Background(GLFWwindow* window)
{
	texture = new Texture("../assets/textures/background.jpg", GL_TEXTURE_2D);

	if (!texture->isValid())
	{
		std::cerr << "Failed to load background image" << std::endl;
	}

	glfwGetWindowSize(window, &WinWidth, &WinHeight);
}

void Background::Draw(Quad& quad, Shader& shader)
{
	shader.Activate();

	glm::mat4 projection = glm::ortho(
		0.0f, (float)WinWidth, 
		0.0f, (float)WinHeight, 
		-1.0f, 1.0f
	);

	glm::mat4 model = glm::mat4(1.f);

	shader.SetMat4("uProjection", projection);
	shader.SetMat4("uModel", model);

	texture->TexUnit(shader, "ourTexture", 0);
	texture->Bind();

	quad.Draw();
}