#version 330 core

out vec4 FragColor;

in mat4 neighbors;

void main()
{
	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

void AntiAlias()
{
	
};