#pragma once

#include "InputCodes.hpp"
#include "Window.hpp"

namespace OGLE {
	class InputHandler {
	public:
		InputHandler(Window& window);
		~InputHandler();

		bool initialize();

		bool isKeyDown(uint32_t inputCode);
		bool isKeyPressed(uint32_t inputCode);

		bool isMouseButtonDown(uint32_t inputCode);
		bool isMouseButtonPressed(uint32_t inputCode);

		float getCursorX();
		float getCursorY();
	private:
		bool mKeys[KEY_LAST];
		bool mMouseButtons[MOUSE_BUTTON_LAST];

		Window& mWindow;
	};
}