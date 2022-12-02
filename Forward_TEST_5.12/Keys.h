#pragma once
#include "Car.h"

void action(GLFWwindow* window, Car& obj)
{
	glm::mat4 trans = glm::identity<glm::mat4>();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		trans = glm::rotate(trans, glm::radians(1.5f), glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		trans = glm::rotate(trans, glm::radians(-1.5f), glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		trans = glm::rotate(trans, glm::radians(1.5f), glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		trans = glm::rotate(trans, glm::radians(-1.5f), glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		trans = glm::translate(trans, glm::vec3(0.0f, 0.01f, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		trans = glm::translate(trans, glm::vec3(0.0f, -0.01f, 0.0f));
	}
	obj.transform(trans);
}
