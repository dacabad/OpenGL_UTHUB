#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shapes.h"

#include "Shader.h"


#define RES_H 800.f
#define RES_W 600.f

namespace glm
{
	void displayMatrix(const glm::mat4& mat)
	{
		std::cout
		<< mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << " " << mat[0][3] << "\n"
		<< mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << " " << mat[1][3] << "\n"
		<< mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << " " << mat[2][3] << "\n"
		<< mat[3][0] << " " << mat[3][1] << " " << mat[3][2] << " " << mat[3][3] << std::endl;
	}

	void displayVector(const glm::vec4& vec)
	{
		std::cout
		<< vec[0] << "\n" << vec[1] << "\n" << vec[2] << "\n" << vec[3] << "\n" << std::endl;
	}
}

class ClassInsideNamespace
{
	
};

//const char* vertexShaderSource =
//	"#version 330 core\n"
//	"layout (location = 0) in vec3 aPos;\n"
//	"void main()\n"
//	"{\n"
//	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//	"}\0";
//
//const char* fragmentShaderSource =
//	"#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"void main()\n"
//	"{\n"
//	"	FragColor = vec4(1.f, 1.f, 1.f, 1.f);\n"
//	"}\0";
//
//const char* fragmentShaderRedSource =
//	"#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"void main()\n"
//	"{\n"
//	"	FragColor = vec4(1.f, 0.f, 0.f, 1.0f);\n"
//	"}\0";

//

class GameObject
{
public:

	glm::mat4 transform;

	void Render();
};

class Renderer
{
public:

	Renderer() { Initialize(); };

	void Initialize();

private:

	std::vector<class GameObject> pendingDraws;

private:

	ShaderProgram shaderProgram;

	void RenderLoop()
	{
		for(auto obj : pendingDraws)
		{
			

			int transformLocation = glGetUniformLocation(shaderProgram.GetShaderProgramId(), "transformMat");
			glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(obj.transform));
		}
	};

};

class VertexBufferObject
{
	
};




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

	unsigned int IBO;
	glGenBuffers(1, &IBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Shapes::vertices), Shapes::vertices, GL_STATIC_DRAW);

	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Shapes::indexVerticesSingle), Shapes::indexVerticesSingle, GL_STATIC_DRAW);*/

	GLsizei stride = 0;
	void* offset = nullptr;

	stride = sizeof(float) * 6;
	offset = (void*)0;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(0);
	

	stride = sizeof(float) * 6;
	offset = (void*)(3 * sizeof(float));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	Shader vertexShader = Shader("Shaders/vertexShader.vert", GL_VERTEX_SHADER);
	Shader fragmentShader = Shader("Shaders/fragmentShader.frag", GL_FRAGMENT_SHADER);
	ShaderProgram shaderProgram = ShaderProgram();
	//shaderProgram.AttachShader(vertexShader);
	//shaderProgram.AttachShader(fragmentShader);
	shaderProgram.AttachShaders({vertexShader, fragmentShader});
	shaderProgram.LinkProgram();


	glm::vec3 forwardVector = glm::vec3(1.f, 0.f, 0.f);
	glm::vec3 rightVector = glm::vec3(0.f, 1.f, 0.f);

	glm::vec3 upVector = glm::cross(forwardVector, rightVector);

	//std::cout << upVector.x << " - " << upVector.y << " - " << upVector.z << " - " << std::endl;

	glm::mat4 idMat = glm::mat4(1.f);
	
	//glm::mat4 translationMatrix = glm::translate(idMat, glm::vec3(0.1f, 0.2f, 0.5f));
	glm::mat4 translationMatrix = glm::translate(idMat, glm::vec3(0.f, 0.f, 0.f));
	//idMat = glm::translate(idMat, glm::vec3(0.1f, 0.2f, 0.5f));

	

	//glm::displayMatrix(translationMatrix);

	glm::mat4 rotMatrix = glm::rotate(idMat, glm::radians(50.f), glm::vec3(0.f, 0.f, 1.f));
	//idMat = glm::rotate(idMat, glm::radians(90.f), forwardVector);

	//glm::displayMatrix(rotMatrix);

	glm::mat4 scaleMat = glm::scale(idMat, glm::vec3(1.f, 1.f, 1.f));
	//idMat = glm::scale(idMat, glm::vec3(2.f, 2.f, 3.f));


	glm::mat4 transform = glm::mat4(1.f);
	
	transform *= translationMatrix;
	transform *= scaleMat;
	transform *= rotMatrix;
	
	glm::vec4 unitVector = glm::vec4(1.f, 0.f, 0.f, 1.f);

	glm::displayVector(unitVector);
	unitVector = rotMatrix * unitVector;
	glm::displayVector(unitVector);
	
	//glm::displayMatrix(transform);

	// T * R * S

	


	// shader program white
	//unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShaderId, 1, &vertexShaderSource, nullptr);
	//glCompileShader(vertexShaderId);

	//unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, nullptr);
	//glCompileShader(fragmentShaderId);
	//
	//unsigned int shaderProgramId = glCreateProgram();
	//glAttachShader(shaderProgramId, vertexShaderId);
	//glAttachShader(shaderProgramId, fragmentShaderId);
	//glLinkProgram(shaderProgramId);

	//// shader program red
	//unsigned int vertexShaderAltId = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShaderAltId, 1, &vertexShaderSource, nullptr);
	//glCompileShader(vertexShaderAltId);

	//unsigned int fragmentShaderAltId = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShaderAltId, 1, &fragmentShaderRedSource, nullptr);
	//glCompileShader(fragmentShaderAltId);
	//
	//unsigned int shaderProgramAltId = glCreateProgram();
	//glAttachShader(shaderProgramAltId, vertexShaderAltId);
	//glAttachShader(shaderProgramAltId, fragmentShaderAltId);
	//glLinkProgram(shaderProgramAltId);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// render loop
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.f, 0.f, 0.f, 0.f);

		glBindVertexArray(VAO);
		
		shaderProgram.UseProgram();

		static glm::mat4 id = glm::mat4(1.f);
		static glm::mat4 translation = glm::translate(id, glm::vec3(0.2f, 0.f, 0.f));
		static glm::mat4 rotation = glm::rotate(id, glm::radians(70.f), glm::vec3(0.f, 0.f, 1.f));
		static glm::mat4 scale = glm::scale(id, glm::vec3(1.2f, 1.2f, 1.2f));
		static glm::mat4 transform = scale * translation * rotation;

		GameObject obj = GameObject();

		int transformLocation = glGetUniformLocation(shaderProgram.GetShaderProgramId(), "transformMat");
		glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(obj.transform));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/*glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);*/
}