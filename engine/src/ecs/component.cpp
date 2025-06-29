#include "ecs/component.hpp"

namespace Engine {

ComponentTypeID GetUniqueComponentTypeID() {
  static ComponentTypeID lastID = 0;
  return lastID++;
}

} // namespace Engine
