#include "Renderer.hpp"

namespace OGLE {
	Renderer::Renderer() {

	}

	Renderer::~Renderer() {

	}

	bool Renderer::initialize() {
		mShader.initialize("resources/shaders/renderer.vert", "resources/shaders/renderer.frag");

		float vertices[] = {
			0.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			1.0f, 0.0f
		};
		unsigned int indices[] = {
			0, 2, 3,
			1, 2, 3
		};

		glGenBuffers(1, &mVertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		if (mVertexBufferObject == NULL) {
			throw std::runtime_error("Failed to create a vertex buffer object.");
		}

		glGenVertexArrays(1, &mVertexArrayObject);
		glBindVertexArray(mVertexArrayObject);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		if (mVertexArrayObject == NULL) {
			throw std::runtime_error("Failed to create a vertex array object.");
		}

		glGenBuffers(1, &mElementBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		if (mElementBufferObject == NULL) {
			throw std::runtime_error("Failed to create an element buffer object.");
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return true;
	}

	void Renderer::shutdown() {
		glDeleteBuffers(1, &mVertexBufferObject);
		glDeleteVertexArrays(1, &mVertexArrayObject);
		glDeleteBuffers(1, &mElementBufferObject);
	}

	void Renderer::render() {
		render(mShader);
	}

	void Renderer::render(Shader& shader) {
		shader.use();

		glBindVertexArray(mVertexArrayObject);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}