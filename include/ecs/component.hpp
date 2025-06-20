#pragma once

#include <cstddef>

namespace Engine {

using ComponentTypeID = std::size_t;

ComponentTypeID GetUniqueComponentTypeID();

template <typename T> ComponentTypeID GetComponentTypeID() {
  static ComponentTypeID typeID = GetUniqueComponentTypeID();
  return typeID;
}

} // namespace Engine
