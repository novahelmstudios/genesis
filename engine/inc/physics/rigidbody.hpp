#pragma once

#include <glm/ext/vector_float2.hpp>

namespace Engine {

struct RigidBody {
  glm::vec2 velocity = {0, 0};
  glm::vec2 acceleration = {0, 0};
  float mass = 1.0f;
  bool isStatic = false;
};

} // namespace Engine
