#pragma once

#include <string>
#include <vector>

class Shader
{
public:

	Shader(const std::string& pathToShader, unsigned int shaderType);

	/*virtual ~Shader() {};*/

	unsigned int GetShaderId() const { return shaderId; }
  
private:

	void LoadShaderFromFile(const std::string& pathToShader, std::string& shaderContents);
	unsigned int shaderId;
};

class ShaderProgram
{
public:
	ShaderProgram();
	void AttachShader(Shader shader);
	void AttachShaders(const std::vector<Shader>& shaderList);
	void LinkProgram();
	void UseProgram();

	unsigned int GetShaderProgramId() const { return shaderProgramId;};
  
private:

	unsigned int shaderProgramId;
};




