#include "core/application.hpp"
#include "core/window.hpp"

Application::Application(int width, int height, const char *title) {
  // init window and other systems here
  init();
}

Application::~Application() { shutdown(); }

void Application::run() {
  while (true /* window not closed */) {
    update();
    render();
  }
}

void Application::init() {
  // init GLFW, GLAD, etc.
}

void Application::update() {
  // handle game logic
}

void Application::render() {
  // draw stuff
}

void Application::shutdown() {
  // cleanup
}
