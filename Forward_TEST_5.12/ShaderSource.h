#pragma once

#include <gl\glew.h>
namespace source {
	const GLchar* vertexshadersource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec3 color;\n"
		"out vec3 ourcolor;\n"
		"void main(){\n"
		"gl_position=vec4(position,0.0f);\n"
		"ourcolor=color;\n"
		"}\n\0";

	const GLchar* fragmentshadersource = "#version 330 core\n"
		"in vec3 ourcolor;\n"
		"in vec4 color;\n"
		"void main(){\n"
		"color = vec3(ourcolor,1.0f);\n"
		"}\n\0";
}