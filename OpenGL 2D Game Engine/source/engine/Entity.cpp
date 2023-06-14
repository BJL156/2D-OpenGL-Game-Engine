#include "Entity.hpp"

namespace OGLE {
	Entity::Entity(glm::vec2 entityPos, glm::vec2 entityScale)
		: pos(entityPos), scale(entityScale) {

	}

	Entity::Entity() {

	}

	Entity::~Entity() {

	}

	bool Entity::isColliding(Entity& entity) {
		return (
			pos.x + scale.x > entity.pos.x && pos.x < entity.pos.x + entity.scale.x &&
			pos.y + scale.y > entity.pos.y && pos.y < entity.pos.y + entity.scale.y
		);
	}
}