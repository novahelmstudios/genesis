#include "game/entity.hpp"

Entity::Entity() : m_position(0.0f) {}

Entity::~Entity() {}

void Entity::update(float deltaTime) {}

void Entity::render() {}

void Entity::setPosition(const glm::vec3& pos) {
    m_position = pos;
}
