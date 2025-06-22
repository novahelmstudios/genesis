#include "animation/animationSystem.hpp"
#include "animation/animator.hpp"
#include "animation/spriteSheet.hpp"

namespace Engine {

void UpdateAnimationSystem(registry &reg, float deltaTime) {
  for (auto e : reg.View<Animator>()) {
    Animator &anim = reg.Get<Animator>(e);

    /* animation finished or never invoked skip that entity */
    if (!anim.playing || anim.sheet == nullptr || anim.sheet->totalFrames <= 0)
      continue;

    anim.elapsed += deltaTime;

    int frame = static_cast<int>(anim.elapsed / anim.sheet->frameDuration);

    if (frame >= anim.sheet->totalFrames) {
      /* if looping is true continue to loop */
      if (anim.looping) {
        anim.elapsed = 0.0f;
        anim.currentFrame = 0;
      } else {
        anim.currentFrame = anim.sheet->totalFrames - 1;
        anim.playing = false;
      }
    } else {
      anim.currentFrame = frame;
    }
  }
}

} // namespace Engine
