#pragma once

#include <string>

namespace Engine {

struct SpriteSheet {
  std::string textureName;
  int frameWidth;
  int frameHeight;
  int column;
  int rows;
  int totalFrames;
  float frameDuration; /* in sec */
};

} // namespace Engine
