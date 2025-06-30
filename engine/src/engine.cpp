// core modules
#include "engine.hpp"
#include "core/application.hpp"
#include "core/time.hpp"

// window manager
#include "window_manager/window.h"

// animation modules
#include "animation/animationSystem.hpp"
#include "animation/animator.hpp"
#include "animation/spriteSheet.hpp"

// ecs modules
#include "ecs/component.hpp"
#include "ecs/entity.hpp"
#include "ecs/registry.hpp"

#include "external/KHR/khrplatform.h"

#include "graphics/camera.hpp"
#include "graphics/font.hpp"
#include "graphics/shader.hpp"
#include "graphics/texture.hpp"

#include "input/inputManager.hpp"

#include "physics/collider.hpp"
#include "physics/force.hpp"
#include "physics/rigidbody.hpp"
#include "physics/transform.hpp"

#include "render/renderSystem.hpp"

#include "resource/resourceManager.hpp"

#include "ui/button.hpp"

#include "window_manager/window.h"
#include <GLFW/glfw3.h>

namespace Engine {
static Window *window = nullptr;

void Engine::init(const EngineConfig &cfg) {
  WindowConfig wcfg;
  wcfg.title = cfg.title;
  wcfg.width = cfg.width;
  wcfg.height = cfg.height;
  wcfg.fullscreen = cfg.bFullscreen;

  window = new Window(wcfg);
}

void Engine::run() {
  while (!window->shouldClose()) {

    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    window->swapBuffers();
    window->pollEvents();
  }
}

void Engine::resign() {
  delete window;
  glfwTerminate();
}

} // namespace Engine
