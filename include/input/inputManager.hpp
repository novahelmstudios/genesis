#pragma once

class InputManager {
public:
  static void initialize(void *window);
  static bool isKeyPressed(int key);
  static bool isMouseButtonPressed(int button);
};
