#pragma once

class Game {
public:
  Game();
  ~Game();

  void init();
  void update(float deltaTime);
  void render();
};
