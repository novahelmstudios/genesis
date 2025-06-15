#include "core/application.hpp"
#include "graphics/font.hpp"
#include "graphics/shader.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <iostream>

Application::Application(float _width, float _height, const char *title)
    : width(_width), height(_height) {
  m_Window = new Window(_width, _height, title);
  init();
}

Application::~Application() { shutdown(); }

void Application::run() {
  Font font("assets/fonts/Inter.ttf", 48);
  font.setProjection(glm::ortho(0.0f, width, 0.0f, height));
  Shader textShader("assets/shaders/text.vert", "assets/shaders/text.frag");

  while (!m_Window->shouldClose()) {
    m_Window->pollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    font.renderText(textShader, "Hello", 100.0f, 100.0f, 1.0f,
                    glm::vec3(1, 1, 1));

    m_Window->swapBuffers();
  }
}

void Application::init() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD\n";
    std::exit(EXIT_FAILURE);
  }

  std::cout << "Application initialized.\n";
}

void Application::update() {
  // handle game logic
}

void Application::render() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  std::cout << "Rendering\n";
}

void Application::shutdown() { delete m_Window; }
