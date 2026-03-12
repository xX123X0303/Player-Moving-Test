#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

#include <glad/glad.h>

std::string get_content_file(const char* filename);

class Shader
{
public:	
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void Activate();
	
};
