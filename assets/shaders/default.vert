#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 uProjection;
uniform mat4 uModel;

void main()
{
	float s = sin(uRotation);
	float c = cos(uRotation);

	vec2 pos = aPos;

	float nx = pos.x * c - pos.y * s;
	float ny = pos.x * s + pos.y * c;

	pos = vec2(nx, ny);
	pos += vec2(uPositionX, uPositionY);

	gl_Position = uProjection * uModel * vec4(pos, 0.f, 1.f);
	TexCoord = aTexCoord;
}