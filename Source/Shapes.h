#pragma once

#include <vector>

namespace Shapes
{
	static float vertices[] = {
		 // X     Y		  Z
		// 0.0f,	0.0f,	0.0f,  0.3f, 1.0f, 0.0f, // v1
		// 0.5f,	0.5f,	0.0f,  1.0f, 0.0f, 0.0f, // v2
		//-0.5f,	0.5f,	0.0f,  0.0f, 1.0f, 1.0f, // v3
		//-0.5f, -0.5f,	0.0f,  0.3f, 1.0f, 0.0f, // v4
		// 0.0f,	0.0f,	0.0f,  0.3f, 1.0f, 0.0f, // v5
		//-0.5f,	0.5f,	0.0f,  0.3f, 1.0f, 0.0f, // v6

		-0.5f,	0.5f,	0.0f,  1.0f, 1.0f, 0.4f, // v1
		-0.5f, -0.5f,	0.0f,  1.0f, 1.0f, 0.4f, // v2
		 0.5f, -0.5f,	0.0f,  1.0f, 1.0f, 0.4f, // v3
		-0.5f,	0.5f,	0.0f,  0.0f, 1.0f, 0.0f, // v4
		 0.5f, -0.5f,	0.0f,  0.0f, 1.0f, 0.0f, // v5
		 0.5f,	0.5f,	0.0f,  0.0f, 1.0f, 0.0f, // v6

		//...
	};

	static std::vector<glm::vec4> verticesInGlm =
		{
			{-0.5f,	0.5f,	0.0f, 1.f},
			{-0.5f,	0.5f,	0.0f, 1.f},
			{-0.5f,	0.5f,	0.0f, 1.f},
			{-0.5f,	0.5f,	0.0f, 1.f},
			{-0.5f,	0.5f,	0.0f, 1.f}
		};

	float verticesSingle[] = 
	{
	    0.5f,  0.5f, 0.0f,
	    0.5f, -0.5f, 0.0f,
	   -0.5f, -0.5f, 0.0f,
	   -0.5f,  0.5f, 0.0f
	};

	unsigned int indexVerticesSingle[] = 
	{
	    0, 1, 3,  
	    1, 2, 3 
	};

}