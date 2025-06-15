#pragma once

#include "window.hpp"

class Application {
public:
  Application(float width, float height, const char *title);
  ~Application();

  void run();

private:
  void init();
  void update();
  void render();
  void shutdown();

  Window* m_Window;
  float width, height;
};
