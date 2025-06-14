#pragma once

class Time {
public:
  static float getDeltaTime();
  static void update();

private:
  static float s_lastTime;
  static float s_deltaTime;
};
