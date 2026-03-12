#include "Player.h"
#include <GLFW/glfw3.h>

Player::Player()
{
	x = 0.0f;
	y = 0.0f;
	speed = 1.0f;
}

void Player::Update(GLFWwindow* window, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) x -= speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) x += speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) y -= speed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) y += speed * deltaTime;
}

void Player::Draw(Quad& quad)
{
	float size = 0.1f;

	quad.Update(x, y, size, size);
	quad.Draw();
}