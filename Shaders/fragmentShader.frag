#version 330 core

out vec4 FragColor;

in vec4 colorFromVertex;

uniform vec4 uniformFragmentColor;

void main()
{
	// FragColor = uniformFragmentColor;
	FragColor = colorFromVertex;
}