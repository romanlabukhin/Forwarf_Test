#include "Shader.h"
#include <sstream>

Shader::Shader(const char* vShadPath, const char* fShadPath)
{

	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShadFile;
	std::ifstream fShadFile;

	try {
		vShadFile.open(vShadPath);

		fShadFile.open(fShadPath);

		std::ostringstream vShaderStream;
		std::ostringstream fShaderStream;

		vShaderStream << vShadFile.rdbuf();
		fShaderStream << fShadFile.rdbuf();

		vShadFile.close();
		fShadFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	}
	catch (std::ifstream::failure & e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESULLY_READ" << e.what() << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();


	unsigned int vertexShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::USE::VERTEX_SHADER::COMPILE_ERROR" << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::USE::FRAGMENT_SHADER::COMPILE_ERROR" << std::endl;
	}

	this->Program = glCreateProgram();
	glAttachShader(this->Program, vertexShader);
	glAttachShader(this->Program, fragmentShader);
	glLinkProgram(this->Program);

	glGetShaderiv(this->Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(this->Program, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::USE::SHADER_PROGRAM::LINK_ERROR" << std::endl;
	}
	else { std::cout << "shader is linked!" << std::endl; }

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	


}

void Shader::Use() {
	glUseProgram(this->Program);
}
