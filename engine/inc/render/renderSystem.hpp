#pragma once

#include "ecs/registry.hpp"
#include "graphics/shader.hpp"

namespace Engine {

class RenderSystem {
public:
  void Render(registry &reg, Shader &shader);
};

} // namespace Engine
