#include "core/window.hpp"
#include <GLFW/glfw3.h>

Window::Window(int width, int height, const std::string& title) {
    glfwInit();
    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent((GLFWwindow*)m_window);
}

Window::~Window() {
    glfwDestroyWindow((GLFWwindow*)m_window);
    glfwTerminate();
}

void Window::swapBuffers() {
    glfwSwapBuffers((GLFWwindow*)m_window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose((GLFWwindow*)m_window);
}

