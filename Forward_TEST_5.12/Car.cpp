#include "Car.h"

Car::Car(const char* vShadFile, const char* fShadPath):Shader(vShadFile, fShadPath)
{

	GLfloat vertices[] = {
		0.1f,  0.2f, 0.0f,  0.0f, 0.0f, 1.0f,
		0.1f, -0.2f, 0.0f,  1.0f, 0.0f, 0.0f,
	   -0.1f, -0.2f, 0.0f,  1.0f, 0.0f, 0.0f,
	   -0.1f,  0.2f, 0.0f,  0.0f, 0.0f, 1.0f
	};

	
	GLuint indices[6] = {  
		0, 1, 3,  
		1, 2, 3   
	};

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);

	this->RecVAO = VAO;
	this->RecVBO = VBO;

	Use();

	trans = glm::identity<glm::mat4>();
	center = glm::vec4(0.0f, 0.0f, 0.0f,1.0f);
}


void Car::Draw()
{
	GLint transformLoc = glGetUniformLocation(Program, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(RecVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Car::transform(glm::mat4 matr)
{
	trans *= matr;
	center =matr * center;
}
