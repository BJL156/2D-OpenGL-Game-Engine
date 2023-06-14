#include "Game.hpp"

#include <iostream>

OGLE::Entity entity{glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f)};
bool renderEntity = false;

void Game::initialize() {

}

void Game::update() {
	renderEntity = mInputHandler.isKeyDown(KEY_SPACE);
}

void Game::render() {
	if (renderEntity) {
		mRenderer.render(entity);
	}
}

void Game::shutdown() {

}