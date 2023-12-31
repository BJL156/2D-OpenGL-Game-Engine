#pragma once

#include <GLM/glm.hpp>

#include "ENGINE/Renderer.hpp"
#include "ENGINE/InputHandler.hpp"
#include "ENGINE/InputCodes.hpp"
#include "ENGINE/Entity.hpp"

class Game {
public:
	Game(OGLE::Renderer& renderer, OGLE::InputHandler& inputHandler)
		: mRenderer(renderer), mInputHandler(inputHandler) {

	}
	~Game() {

	}

	void initialize();
	void update();
	void render();
	void shutdown();
private:
	OGLE::Renderer& mRenderer;
	OGLE::InputHandler& mInputHandler;
};