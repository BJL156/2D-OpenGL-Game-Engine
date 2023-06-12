#include "Window.hpp"

namespace OGLE {
	Window::Window(uint32_t width, uint32_t height, std::string title)
		: mWidth(width), mHeight(height), mTitle(title) {

	}

	Window::~Window() {

	}

	bool Window::initialize() {
		if (!glfwInit()) {
			throw std::runtime_error("Failed to initialize GLFW.");
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
		if (mWindow == nullptr) {
			throw std::runtime_error("Failed to create a GLFW window.");
			return false;
		}
		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			throw std::runtime_error("Failed to initialize GLAD.");
			return false;
		}
	}

	void Window::shutdown() {
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	void Window::update() {
		glfwSwapBuffers(mWindow);
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
	}
}