#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/type_ptr.hpp>

#include <fstream>
#include <string>
#include <iostream>

namespace OGLE {
	class Shader {
	public:
		Shader();
		Shader(const std::string vertexShaderFilepath, const std::string fragmentShaderFilepath);
		~Shader();

		void initialize(const std::string vertexShaderFilepath, const std::string fragmentShaderFilepath);

		void use() { glUseProgram(id); }

		void setMat4(std::string name, glm::mat4 mat4) { glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat4)); }
		void setInt(std::string name, int val) { glUniform1i(glGetUniformLocation(id, name.c_str()), val); }
	private:
		void createShaderProgram(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);

		static std::string getFileContents(const std::string& filepath);
		static bool isShaderCompiled(unsigned int shader);
		static bool isProgramLinked(unsigned int program);

		unsigned int id;
	};
}