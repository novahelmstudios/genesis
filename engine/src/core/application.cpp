#include "core/application.hpp"
#include "graphics/font.hpp"
#include "graphics/shader.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <iostream>

Engine::Application::Application(float _width, float _height, const char *title)
    : width(_width), height(_height) {
  m_Window = new Window(_width, _height, title);
  init();
}

Engine::Application::~Application() { shutdown(); }

void Engine::Application::run() {
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Font font("assets/fonts/Inter.ttf", 48);
  font.setProjection(glm::ortho(0.0f, width, 0.0f, height));
  Shader textShader("assets/shaders/text.vert", "assets/shaders/text.frag");

  while (!m_Window->shouldClose()) {
    m_Window->pollEvents();

    // ============ BACKGROUND COLOR ============
    // Set background color (R, G, B, Alpha) - values from 0.0 to 1.0
    glClearColor(0.0f, 0.1f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    // ============ TEXT COLOR ============
    // Text color is set in the renderText call as glm::vec3(R, G, B)
    font.renderText(textShader, "Genesis", 400.0f, 400.0f, 1.0f,
                    glm::vec3(0.5f, 1.0f, 0.0f));

    m_Window->swapBuffers();
  }
}

void Engine::Application::init() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD\n";
    std::exit(EXIT_FAILURE);
  }

  std::cout << "Application initialized.\n";
}

void Engine::Application::update() {
  // handle game logic
}

void Engine::Application::render() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  std::cout << "Rendering\n";
}

void Engine::Application::shutdown() { delete m_Window; }
