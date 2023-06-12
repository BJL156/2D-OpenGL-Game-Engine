#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include <string>
#include <stdexcept>

namespace OGLE {
	class Window {
	public:
		Window(uint32_t width, uint32_t height, std::string title);
		~Window();

		bool initialize();
		void shutdown();

		void update();

		bool shouldClose() { return glfwWindowShouldClose(mWindow); }

		uint32_t getWidth() { return mWidth; }
		uint32_t getHeight() { return mHeight; }
		GLFWwindow* getWindow() { return mWindow; }
	private:
		uint32_t mWidth, mHeight;
		std::string mTitle;
		GLFWwindow* mWindow;
	};
}