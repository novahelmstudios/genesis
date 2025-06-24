#pragma once

#include <glm/ext/vector_float2.hpp>

namespace Engine {

struct Collider {
  glm::vec2 size;
  glm::vec2 offset = {0, 0};
  bool isTrigger = false;
};

} // namespace Engine
