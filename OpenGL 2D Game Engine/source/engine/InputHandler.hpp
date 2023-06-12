#pragma once

#include "InputCodes.hpp"
#include "Window.hpp"

namespace OGLE {
	class InputHandler {
	public:
		InputHandler();
		~InputHandler();

		bool initialize(Window& window);

		bool isKeyDown(Window& window, uint32_t inputCode);
		bool isKeyPressed(Window& window, uint32_t inputCode);

		bool isMouseButtonDown(Window& window, uint32_t inputCode);
		bool isMouseButtonPressed(Window& window, uint32_t inputCode);

		float getCursorX(Window& window);
		float getCursorY(Window& window);
	private:
		bool mKeys[KEY_LAST];
		bool mMouseButtons[MOUSE_BUTTON_LAST];
	};
}