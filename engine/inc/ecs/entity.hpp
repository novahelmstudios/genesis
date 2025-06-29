#pragma once

#include <cstdint>

namespace Engine {

using EntityID = std::uint32_t;

constexpr EntityID NULL_ENTITY = static_cast<EntityID>(-1);

struct Entity {
  EntityID id = NULL_ENTITY;

  bool isValid() const;
  bool operator==(const Entity &other);
  bool operator!=(const Entity &other);

  operator EntityID() const;
};

} // namespace Engine
