#include "core/window.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

Engine::Window::Window(int width, int height, const std::string &title) {
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  /* setting my OpenGL version to 4.6*/
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!m_window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }

  glfwMakeContextCurrent((GLFWwindow *)m_window);
  std::cout << "Window created\n";
}

Engine::Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void Engine::Window::swapBuffers() { glfwSwapBuffers(m_window); }

void Engine::Window::pollEvents() { glfwPollEvents(); }

bool Engine::Window::shouldClose() const {
  return glfwWindowShouldClose(m_window);
}

GLFWwindow *Engine::Window::getNativeHandle() const { return m_window; }
