#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 colorFromVertex;

uniform float horizontalDisplacement;
uniform float scaleFactor;
uniform mat4 transformMat;

void main()
{
   // vec2 newPos = aPos.xy * scaleFactor;

   vec4 newPos = transformMat * vec4(aPos, 1.f);

   colorFromVertex = vec4(aColor, 1.f);

   // gl_Position = vec4(newPos.xy, aPos.z, 1.0f); 
   gl_Position = newPos; 
}
