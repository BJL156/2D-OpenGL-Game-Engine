#pragma once

#include <GLM/glm.hpp>

namespace OGLE {
	class Entity {
	public:
		Entity(glm::vec2 entityPos, glm::vec2 entityScale);
		Entity();
		~Entity();

		bool isColliding(Entity& entity);

		glm::vec2 pos = glm::vec2(0.0f);
		glm::vec2 scale = glm::vec2(0.0f);
	};
}