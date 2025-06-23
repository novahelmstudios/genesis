#pragma once

#include <glm/vec2.hpp>

struct Force {
  glm::vec2 force = {0.0f, 0.0f};
  glm::vec2 impulse = {0.0f, 0.0f};

  void Clear(){
      force = {0.0f, 0.0f};
      impulse = {0.0f, 0.0f};
  }
};
