#pragma once

#include <string>

using std::string;

namespace Engine {

/*
 * Describes how to interpret a sprite sheet texture for animation
 *
 * This data does not render anything; it’s used by the Animator system
 * to update the Sprite's `texCoordinates` over time
 *
 * - `frameWidth` and `frameHeight` are the dimensions of one frame in pixels
 * - `columns` and `rows` define the layout of the sprite sheet
 * - `totalFrames` is how many frames are animated (can be < columns * rows)
 * - `frameDuration` is how long each frame is shown (in seconds)
 */
struct SpriteSheet {
  string textureName;

  int frameWidth;
  int frameHeight;

  int column;
  int rows;

  int totalFrames;
  float frameDuration; /* in sec */

  SpriteSheet(const string &tex, int fw = 0, int fh = 0, int col = 0, int r = 0,
              int _totalFrames = 0, float dur = 0.0f)
      : textureName(tex), frameWidth(fw), frameHeight(fh), column(col), rows(r),
        totalFrames(_totalFrames), frameDuration(dur) {}
};

} // namespace Engine
