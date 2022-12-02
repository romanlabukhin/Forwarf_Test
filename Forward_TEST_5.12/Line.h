#pragma once

#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Line : public Shader {
private:
	GLuint RecVAO;
	GLuint RecVBO;
	glm::mat4 trans;
	
public:
	Line(const char* vShadFile, const char* fShadPath);
	~Line() { std::cout << "Rectangle is successufully destroyed"; };

	void transform(glm::mat4 matr);
	
	void Draw();
};
