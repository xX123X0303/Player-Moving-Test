#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

std::string get_content_file(const char* filename);

class Shader
{
public:	
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void Activate();
	void SetFloat(const std::string& name, float value) const;
	void SetMat4(const std::string& name, glm::mat4& value) const;
	
};
