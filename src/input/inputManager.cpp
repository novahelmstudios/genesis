#include "input/inputManager.hpp"
#include <GLFW/glfw3.h>

static GLFWwindow* s_window = nullptr;

void InputManager::initialize(void* window) {
    s_window = static_cast<GLFWwindow*>(window);
}

bool InputManager::isKeyPressed(int key) {
    return glfwGetKey(s_window, key) == GLFW_PRESS;
}

bool InputManager::isMouseButtonPressed(int button) {
    return glfwGetMouseButton(s_window, button) == GLFW_PRESS;
}
