#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/matrix_transform.hpp>

#include "Shader.hpp"
#include "Entity.hpp"
#include "Window.hpp"

#include <stdexcept>

namespace OGLE {
	class Renderer {
	public:
		Renderer(Window& window);
		~Renderer();

		bool initialize();
		void shutdown();

		void render(Entity& entity);
		void render(Entity& entity, Shader& shader);
	private:
		unsigned int mVertexBufferObject;
		unsigned int mVertexArrayObject;
		unsigned int mElementBufferObject;

		Shader mShader;
		Window& mWindow;
	};
}