#include "Player.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Player::Player(GLFWwindow* window)
{
	texture = new Texture("../assets/textures/survivor.png", GL_TEXTURE_2D);

	if (!texture->isValid())
	{
		std::cerr << "Failed to load player image" << std::endl;
	}

	glfwGetWindowSize(window, &WinWidth, &WinHeight);

	ImgWidth = (texture->GetWidthImg() / (float)WinWidth) * 2.0f;
	ImgHeight = (texture->GetHeightImg() / (float)WinHeight) * 2.0f;

}

void Player::Update(GLFWwindow* window, float deltaTime)
{
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);

	float mx = (float)((mouseX / WinWidth) * 2.0f - 1.0);
	float my = (float)(1.0 - (mouseY / WinHeight) * 2.0f);

	float dx = mx - x;
	float dy = my - y;

	rotation = atan2(dy, dx);

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) x -= speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) x += speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) y -= speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) y += speed * deltaTime;
}

void Player::Draw(Quad& quad, Shader& shader)
{
	shader.Activate();

	glm::mat4 projection = glm::ortho(
		 0.0f, (float)WinWidth,
		 0.0f, (float)WinHeight,
		-1.0f, 1.0f
	);

	shader.SetMat4("uProjection", projection);

	glm::mat4 model = glm::mat4(1.f);
	model = glm::translate(model, glm::vec3(x, y, 0.f));

	model = glm::translate(model, glm::vec3(ImgWidth/2.0f, ImgHeight/2.0f, 0.f));
	model = glm::rotate(model, rotation, glm::vec3(0.f, 0.f, 0.f));
	model = glm::translate(model, glm::vec3(-ImgWidth/2.0f, -ImgHeight/2.0f, 0.f));

	model = glm::scale(model, glm::vec3(ImgWidth, ImgHeight, 1.0f));

	shader.SetMat4("uModel", projection);

	texture->TexUnit(shader, "ourTexture", 0);
	texture->Bind();
	
	quad.Draw();
}