#pragma once

#include <string>

using std::string;

namespace Engine {

struct SpriteSheet {
  string textureName;

  int frameWidth;
  int frameHeight;

  int column;
  int rows;

  int totalFrames;
  float frameDuration; /* in sec */

  SpriteSheet(const string &tex, int fw = 0, int fh = 0, int col = 0,
              int r = 0, int _totalFrames = 0, float dur = 0.0f)
      : textureName(tex), frameWidth(fw), frameHeight(fh), column(col), rows(r),
        totalFrames(_totalFrames), frameDuration(dur) {}
};

} // namespace Engine
