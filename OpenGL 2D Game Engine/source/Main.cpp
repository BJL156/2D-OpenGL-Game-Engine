#include "ENGINE/Engine.hpp"

#include <stdexcept>
#include <iostream>

int main() {
	OGLE::Engine engine;

	try {
		engine.initialize();
		engine.run();
		engine.shutdown();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}