#include "Shader.h"

#include <sstream>
#include <fstream>
#include <iostream>

#include "glad/glad.h"


Shader::Shader(const std::string& pathToShader, unsigned int shaderType)
{
	shaderId = glCreateShader(shaderType);

	std::string shaderContent;
	LoadShaderFromFile(pathToShader, shaderContent);
	
	const char* shaderChar = shaderContent.c_str(); 

	glShaderSource(shaderId, 1, &shaderChar, nullptr);
	glCompileShader(shaderId);
}

void Shader::LoadShaderFromFile(const std::string& pathToShader, std::string& shaderContents)
{
	std::ifstream istream;
	istream.open(pathToShader);
	
	if(istream.is_open())
	{
		std::stringstream ss;
		ss << istream.rdbuf();

		shaderContents = ss.str();

		istream.close();
	}
}

ShaderProgram::ShaderProgram()
{
	shaderProgramId = glCreateProgram();
}

void ShaderProgram::AttachShader(Shader shader)
{
	glAttachShader(shaderProgramId, shader.GetShaderId());
}

void ShaderProgram::AttachShaders(const std::vector<Shader>& shaderList)
{
	for(const Shader& shader : shaderList)
	{
		glAttachShader(shaderProgramId, shader.GetShaderId());
	}
}

void ShaderProgram::LinkProgram()
{
	glLinkProgram(shaderProgramId);
}

void ShaderProgram::UseProgram()
{
	glUseProgram(shaderProgramId);
}