#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shapes.h"


#define RES_H 800.f
#define RES_W 600.f


const char* vertexShaderSource =
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char* fragmentShaderSource =
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.f, 1.f, 1.f, 1.f);\n"
	"}\0";

const char* fragmentShaderRedSource =
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.f, 0.f, 0.f, 1.0f);\n"
	"}\0";

//
class Renderer
{
public:

	Renderer() { Initialize(); };

	void Initialize();

private:

	void RenderLoop()
	{
		
	};

};

class VertexBufferObject
{
	
};

class Shader
{
	
};

class ShaderProgram
{
	
};
//

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
   glViewport(0, 0, width, height);
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(RES_W, RES_H, "My Main Window", nullptr, nullptr);
	if(!window)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	std::cout << "Program has started" << std::endl;


	// Vertex Buffer Object VBO

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Shapes::vertices), Shapes::vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	GLsizei stride = sizeof(float) * 3;
	void* offset = (void*)0;

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, offset);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// shader program white
	unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShaderId);

	unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShaderId);
	
	unsigned int shaderProgramId = glCreateProgram();
	glAttachShader(shaderProgramId, vertexShaderId);
	glAttachShader(shaderProgramId, fragmentShaderId);
	glLinkProgram(shaderProgramId);

	// shader program red
	unsigned int vertexShaderAltId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderAltId, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShaderAltId);

	unsigned int fragmentShaderAltId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderAltId, 1, &fragmentShaderRedSource, nullptr);
	glCompileShader(fragmentShaderAltId);
	
	unsigned int shaderProgramAltId = glCreateProgram();
	glAttachShader(shaderProgramAltId, vertexShaderAltId);
	glAttachShader(shaderProgramAltId, fragmentShaderAltId);
	glLinkProgram(shaderProgramAltId);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	// render loop
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.f, 0.f, 0.f, 0.f);

		glBindVertexArray(VAO);

		// drawcall 1
		glUseProgram(shaderProgramId);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// drawcall 2
		glUseProgram(shaderProgramAltId);
		glDrawArrays(GL_TRIANGLES, 3, 3);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
}