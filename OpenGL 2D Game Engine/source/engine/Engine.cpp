#include "Engine.hpp"

namespace OGLE {
	Engine::Engine() {

	}

	Engine::~Engine() {

	}

	bool Engine::initialize() {
		if (!mWindow.initialize()) {
			throw std::runtime_error("Failed to initialize a window.");
			return false;
		}

		if (!mInputHandler.initialize()) {
			throw std::runtime_error("Failed to initialize a input system.");
			return false;
		}

		if (!mRenderer.initialize()) {
			throw std::runtime_error("Failed to initialize a renderer.");
			return false;
		}

		mGame.initialize();

		return true;
	}

	void Engine::run() {
		while (!mWindow.shouldClose()) {
			mWindow.update();
			mGame.update();
			mGame.render();
		}
	}

	void Engine::shutdown() {
		mGame.shutdown();
		mRenderer.shutdown();
		mWindow.shutdown();
	}
}