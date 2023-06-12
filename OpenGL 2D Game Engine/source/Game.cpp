#include "Game.hpp"

#include <iostream>

void Game::initialize() {
	// std::cout << "Initializing..." << std::endl;
}

void Game::update() {
	// std::cout << "Updating..." << std::endl;
	mRenderer.render();
}

void Game::render() {
	// std::cout << "Rendering..." << std::endl;
}

void Game::shutdown() {
	// std::cout << "Shutting down..." << std::endl;
}