#include "InputHandler.hpp"

namespace OGLE {
	InputHandler::InputHandler(Window& window)
		: mWindow(window) {

	}

	InputHandler::~InputHandler() {

	}

	bool InputHandler::initialize() {
		for (size_t i = 0; i < KEY_LAST; i++) {
			mKeys[i] = false;
		}

		for (size_t i = 0; i < MOUSE_BUTTON_LAST; i++) {
			mMouseButtons[i] = false;
		}

		return true;
	}

	bool InputHandler::isKeyDown(uint32_t inputCode) {
		return glfwGetKey(mWindow.getWindow(), inputCode) == GLFW_PRESS;
	}

	bool InputHandler::isKeyPressed(uint32_t inputCode) {
		if (glfwGetKey(mWindow.getWindow(), inputCode) == GLFW_PRESS && !mKeys[inputCode]) {
			mKeys[inputCode] = true;
			return true;
		} else if (glfwGetKey(mWindow.getWindow(), inputCode) == GLFW_RELEASE) {
			mKeys[inputCode] = false;
		}

		return false;
	}

	bool InputHandler::isMouseButtonDown(uint32_t inputCode) {
		return glfwGetMouseButton(mWindow.getWindow(), inputCode) == GLFW_PRESS;
	}

	bool InputHandler::isMouseButtonPressed(uint32_t inputCode) {
		if (glfwGetMouseButton(mWindow.getWindow(), inputCode) == GLFW_PRESS && !mMouseButtons[inputCode]) {
			mMouseButtons[inputCode] = true;
			return true;
		} else if (glfwGetMouseButton(mWindow.getWindow(), inputCode) == GLFW_RELEASE) {
			mMouseButtons[inputCode] = false;
		}

		return false;
	}

	float InputHandler::getCursorX() {
		double x;
		glfwGetCursorPos(mWindow.getWindow(), &x, nullptr);
		return static_cast<float>(x);
	}
	
	float InputHandler::getCursorY() {
		double y;
		glfwGetCursorPos(mWindow.getWindow(), nullptr, &y);
		return static_cast<float>(y);
	}
}