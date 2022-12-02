
#include "Keys.h"
#include <iostream>
#include "Car.h"
#include "Line.h"

const GLuint WIDTH = 800, HEIGHT = 800;
void action(GLFWwindow* window, Car& obj);

int main()
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Forward", nullptr, nullptr);
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;

	glewInit();

	glViewport(0, 0, WIDTH, HEIGHT);
	

	
	Car carObj("VertexShader.txt", "FragmentShader.txt");
	
	glm::mat4 transform = glm::identity<glm::mat4>();
	transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	carObj.transform(transform);

	Line line1("VertexShader.txt", "FragmentShader.txt");

 	Line line2("VertexShader.txt", "FragmentShader.txt");

	glm::mat4 transLine = glm::identity<glm::mat4>();
	transLine = glm::translate(transLine, glm::vec3(0.0f, -1.2f, 0.0f));
	line2.transform(transLine);


	while (!glfwWindowShouldClose(window))
	{
		action(window, carObj);
		glfwPollEvents();
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		line2.Draw();
		line1.Draw();
		carObj.Draw();
	
	

		glfwSwapBuffers(window);
		
	}

	glfwTerminate();
	return 0;
}


bool CheckCrossing(Car ourCar, Line ourLine) {
	return 1;
}