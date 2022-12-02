#pragma once
#include <GL\glew.h>
#include <glfw3.h>
#include <iostream>
#include <string>
#include <fstream>

class Shader {
public:
	GLuint Program;
	Shader(const char* vShadFile, const char* fShadPath);
	~Shader() {};
	Shader() { };
	void Use();
	

};