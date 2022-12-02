#pragma once

#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Car : public Shader{
private:
	GLuint RecVAO;
	GLuint RecVBO;
	glm::mat4 trans;

public:
	Car(const char* vShadFile, const char* fShadPath);
	~Car() { std::cout << "Rectangle is successufully destroyed"; };

	glm::vec4 center;
	void Draw();

	void transform(glm::mat4 matr);
};

