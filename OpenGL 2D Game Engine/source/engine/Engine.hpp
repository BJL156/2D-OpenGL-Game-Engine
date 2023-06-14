#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "../Game.hpp"

namespace OGLE {
	class Engine {
	public:
		Engine();
		~Engine();

		bool initialize();
		void run();
		void shutdown();
	private:
		// TODO: Game engine components
		Window mWindow{800, 600, "OGLE App"};
		InputHandler mInputHandler{mWindow};
		Renderer mRenderer{mWindow};
		Game mGame{mRenderer, mInputHandler};
	};
}