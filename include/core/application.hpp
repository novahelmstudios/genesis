#pragma once

class Application {
public:
  Application(int width, int height, const char *title);
  ~Application();

  void run();

private:
  void init();
  void update();
  void render();
  void shutdown();
};
