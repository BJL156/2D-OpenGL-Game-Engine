#include "Shader.hpp"

OGLE::Shader::Shader() {

}

OGLE::Shader::Shader(const std::string vertexShaderFilepath, const std::string fragmentShaderFilepath) {
	createShaderProgram(vertexShaderFilepath, fragmentShaderFilepath);
}

OGLE::Shader::~Shader() {
	glDeleteProgram(id);
}

void OGLE::Shader::initialize(const std::string vertexShaderFilepath, const std::string fragmentShaderFilepath) {
	createShaderProgram(vertexShaderFilepath, fragmentShaderFilepath);
}

void OGLE::Shader::createShaderProgram(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath) {
	std::string vertexCode = getFileContents(vertexShaderFilepath);
	std::string fragmentCode = getFileContents(fragmentShaderFilepath);

	std::cout << vertexCode << std::endl;
	std::cout << fragmentCode << std::endl;

	const char* vertexShaderSource = vertexCode.c_str();
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	if (!isShaderCompiled(vertexShader)) {
		throw std::runtime_error("Vertex shader compilation failed.");
	}

	const char* fragmentShaderSource = fragmentCode.c_str();
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	if (!isShaderCompiled(fragmentShader)) {
		throw std::runtime_error("Fragment shader compilation failed.");
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);
	if (!isProgramLinked(id)) {
		throw std::runtime_error("Shader program link failed.");
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

std::string OGLE::Shader::getFileContents(const std::string& filepath) {
	std::ifstream file(filepath);
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open the file: " + filepath);
		return "";
	}

	std::istreambuf_iterator<char> iterator(file), eof;
	std::string contents(iterator, eof);

	file.close();
	return contents;
}

bool OGLE::Shader::isShaderCompiled(unsigned int shader) {
	int success;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << "Failed to compile shader: " << infoLog << std::endl;
		return false;
	}

	return true;
}

bool OGLE::Shader::isProgramLinked(unsigned int program) {
	int success;
	char infoLog[512];

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << "Failed to link the shader program: " << infoLog << std::endl;
		return false;
	}

	return true;
}