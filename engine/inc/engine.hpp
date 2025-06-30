#pragma once

namespace Engine {

struct EngineConfig {
  int width = 1280;
  int height = 720;

  const char *title = "Game";
  bool bFullscreen = true;

  EngineConfig();
};

class Engine {
public:
  Engine();

  static void init(const EngineConfig&);
  static void run();
  static void resign();

  ~Engine();
};

} // namespace Engine
