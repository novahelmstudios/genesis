#include "core/window.hpp"
#include <iostream>
#include <stdexcept>

Window::Window(int width, int height, const std::string &title) {
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!m_window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }

  glfwMakeContextCurrent((GLFWwindow *)m_window);
  std::cout << "Window created\n";
}

Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void Window::swapBuffers() { glfwSwapBuffers(m_window); }

void Window::pollEvents() { glfwPollEvents(); }

bool Window::shouldClose() const { return glfwWindowShouldClose(m_window); }

GLFWwindow *Window::getNativeHandle() const { return m_window; }
