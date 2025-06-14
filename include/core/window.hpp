#pragma once
#include <string>

class Window {
public:
  Window(int width, int height, const std::string &title);
  ~Window();

  void swapBuffers();
  void pollEvents();
  bool shouldClose() const;

private:
  void *m_window;
};
