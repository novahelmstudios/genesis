#pragma once

#include "graphics/texture.hpp"

#include <cstddef>
#include <glm/ext/vector_float2.hpp>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace Engine {

using ComponentTypeID = std::size_t;

ComponentTypeID GetUniqueComponentTypeID();

template <typename T> ComponentTypeID GetComponentTypeID() {
  static ComponentTypeID typeID = GetUniqueComponentTypeID();
  return typeID;
}

/*
 * Represents the position, rotation, and scale of an entity in 2D space
 * - `position` is in world units.
 * - `rotation` is in radians, counter-clockwise.
 * - `scale` is a multiplier (1.0 = original size).
 */
struct Transform {
  glm::vec2 position;
  float rotation;
  glm::vec2 scale;
};

/*
 * Holds data required to render a 2D sprite.
 * - `texture` is the image to be drawn.
 * - `texCoordinates` defines the sub-rectangle of the texture to use (UV
 * coords) This is what allows drawing a specific animation frame or tile
 *
 *  - `color` is a tint (white = no tint); can be used for fade effects, etc
 */
struct Sprite {
  Texture *texture;
  glm::vec4 texCoordinates;
  glm::vec4 color;
};

/*
 *  Represents the movement velocity of an entity
 *  This is used by Physics or Movement systems to update the `Transform`
 */
struct Velocity {
  glm::vec2 velocity;
};

/*
 * Tags
 *
 * easy filtering:
 * reg.view<Transform, Sprite, Player>();
 * reg.view<Transform, Camera>();
 */
struct Player {};
struct Enemy {};
struct Camera {};

} // namespace Engine
