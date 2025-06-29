#include "input/inputManager.hpp"
#include <GLFW/glfw3.h>
#include <cstring>
#include <glm/ext/vector_float2.hpp>

static GLFWwindow *s_window = nullptr;

bool Engine::InputManager::key[349] = {false};
bool Engine::InputManager::keyPrev[349] = {false};

bool Engine::InputManager::mouse[8] = {false};
bool Engine::InputManager::mousePrev[8] = {false};

double Engine::InputManager::mouseX = 0.0;
double Engine::InputManager::mouseY = 0.0;

void Engine::InputManager::init(GLFWwindow *win) { s_window = win; }

/*
 * Updates the state of the keys being pressedevery frame against
 * the key & mouse array
 * Prev State is copied to the keyPrev & mousePrev array
 */
void Engine::InputManager::update() {
  memcpy(keyPrev, key, sizeof key);
  memcpy(mousePrev, mouse, sizeof mouse);

  for (int i = 0; i < 349; ++i)
    key[i] = glfwGetKey(s_window, i) == GLFW_PRESS;

  for (int i = 0; i < 349; ++i)
    mouse[i] = glfwGetMouseButton(s_window, i) == GLFW_PRESS;

  glfwGetCursorPos(s_window, &mouseX, &mouseY);
}

/* Sends the key that is to
 * be checked and is checked
 * against the array
 *
 * for eg
 *
 * key: (current state)
 * Q W E R T Y ...
 * 1 1 0 0 0 0 ...
 *
 * keyPrev: (stored state)
 * Q W E R T Y ...
 * 1 0 1 0 0 0 ...
 *
 * IsKeyDown(GLFW_KEY_Q) -> return True
 * IsKeyPressed(GLFW_KEY_W) -> return True
 * IsKeyReleased(GLFW_KEY_E) -> return True
 */
bool Engine::InputManager::IsKeyDown(int _key) { return key[_key]; }

bool Engine::InputManager::IsKeyPressed(int _key) {
  return key[_key] && !keyPrev[_key];
}

bool Engine::InputManager::IsKeyReleased(int _key) {
  return !key[_key] && keyPrev[_key];
}

bool Engine::InputManager::IsMouseDown(int button) { return mouse[button]; }

glm::vec2 Engine::InputManager::GetMousePos() {
  return glm::vec2(mouseX, mouseY);
}
