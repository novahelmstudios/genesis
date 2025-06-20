#pragma once

#include "graphics/spriteSheet.hpp"
namespace Engine {

struct AnimationClip {
  int startFrame;
  int frameCount;
  bool looping = true;
};

struct Animator {
  const SpriteSheet *sheet = nullptr;

  float elapsed = 0.0f;
  int currentFrame = 0;
  bool playing = true;
  bool looping = true;

  void play(const SpriteSheet *newSheet, bool loop = true) {
    if (sheet != newSheet) {
      sheet = newSheet;
      elapsed = 0.0f;
      currentFrame = 0;
      playing = true;
      looping = loop;
    }
  }
};

} // namespace Engine
