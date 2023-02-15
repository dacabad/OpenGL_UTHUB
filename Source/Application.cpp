#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#define RES_H 800
#define RES_W 600

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

	while(true){}

	std::cout << "Program has started" << std::endl;	
}