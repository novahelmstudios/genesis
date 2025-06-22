#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Engine {

class Window {
public:
  Window(int width, int height, const std::string &title);
  ~Window();

  void swapBuffers();
  void pollEvents();
  bool shouldClose() const;
  GLFWwindow *getNativeHandle() const;

private:
  GLFWwindow *m_window;
};

} // namespace Engine
