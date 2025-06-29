#pragma once

#include <GLFW/glfw3.h>
#include <glm/ext/vector_float2.hpp>

namespace Engine {

enum MouseButton { MOUSE_LEFT = 0, MOUSE_RIGHT = 1 };

class InputManager {
public:
  static void init(GLFWwindow *window);
  static void update();

  static bool IsKeyDown(int _key);
  static bool IsKeyPressed(int _key);
  static bool IsKeyReleased(int _key);

  static bool IsMouseDown(int button);
  static glm::vec2 GetMousePos();

private:
  static GLFWwindow *window;
  static bool key[349];
  static bool keyPrev[349];
  static bool mouse[8];
  static bool mousePrev[8];
  static double mouseX, mouseY;
};

} // namespace Engine
