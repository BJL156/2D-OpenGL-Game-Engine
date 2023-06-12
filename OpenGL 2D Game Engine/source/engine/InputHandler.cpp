#include "InputHandler.hpp"

namespace OGLE {
	InputHandler::InputHandler() {

	}

	InputHandler::~InputHandler() {

	}

	bool InputHandler::initialize(Window& window) {
		for (size_t i = 0; i < KEY_LAST; i++) {
			mKeys[i] = false;
		}

		for (size_t i = 0; i < MOUSE_BUTTON_LAST; i++) {
			mMouseButtons[i] = false;
		}

		return true;
	}

	bool InputHandler::isKeyDown(Window& window, uint32_t inputCode) {
		return glfwGetKey(window.getWindow(), inputCode) == GLFW_PRESS;
	}

	bool InputHandler::isKeyPressed(Window& window, uint32_t inputCode) {
		if (glfwGetKey(window.getWindow(), inputCode) == GLFW_PRESS && !mKeys[inputCode]) {
			mKeys[inputCode] = true;
			return true;
		} else if (glfwGetKey(window.getWindow(), inputCode) == GLFW_RELEASE) {
			mKeys[inputCode] = false;
		}

		return false;
	}

	bool InputHandler::isMouseButtonDown(Window& window, uint32_t inputCode) {
		return glfwGetMouseButton(window.getWindow(), inputCode) == GLFW_PRESS;
	}

	bool InputHandler::isMouseButtonPressed(Window& window, uint32_t inputCode) {
		if (glfwGetMouseButton(window.getWindow(), inputCode) == GLFW_PRESS && !mMouseButtons[inputCode]) {
			mMouseButtons[inputCode] = true;
			return true;
		} else if (glfwGetMouseButton(window.getWindow(), inputCode) == GLFW_RELEASE) {
			mMouseButtons[inputCode] = false;
		}

		return false;
	}

	float InputHandler::getCursorX(Window& window) {
		double x;
		glfwGetCursorPos(window.getWindow(), &x, nullptr);
		return static_cast<float>(x);
	}
	
	float InputHandler::getCursorY(Window& window) {
		double y;
		glfwGetCursorPos(window.getWindow(), nullptr, &y);
		return static_cast<float>(y);
	}
}