#pragma once

#include <GLAD/glad.h>

#include "Shader.hpp"

#include <stdexcept>

namespace OGLE {
	class Renderer {
	public:
		Renderer();
		~Renderer();

		bool initialize();
		void shutdown();

		void render();
		void render(Shader& shader);
	private:
		unsigned int mVertexBufferObject;
		unsigned int mVertexArrayObject;
		unsigned int mElementBufferObject;

		Shader mShader;
	};
}