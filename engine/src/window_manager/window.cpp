#define STB_IMAGE_IMPLEMENTATION

#include "window_manager/window.h"
#include "stb_image.h"
#include <print>

Engine::Window::Window(const WindowConfig &cfg) : config(cfg) {
  if (!glfwInit()) {
    std::println("Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  monitor = config.fullscreen ? glfwGetPrimaryMonitor()
                              : nullptr; // return monitor object if true
  mode = glfwGetVideoMode(
      glfwGetPrimaryMonitor()); // returns video mode of primary monitor to the
                                // video mode object

  if (!mode) {
    std::println("Failed to get video mode\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // setting up hints before window creation
  glfwWindowHint(GLFW_RED_BITS, mode->redBits);
  glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
  glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
  glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
  glfwWindowHint(GLFW_DECORATED, config.decorated);
  glfwWindowHint(GLFW_RESIZABLE, config.resizable);
  glfwWindowHint(GLFW_MAXIMIZED, config.maximized);

  window = glfwCreateWindow(config.fullscreen ? mode->width : config.width,
                            config.fullscreen ? mode->height : config.height,
                            config.title.c_str(), monitor, nullptr);

  if (!window) {
    std::print("Failed to create GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  setupCallbacks();
}

Engine::Window::~Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Engine::Window::pollEvents() { glfwPollEvents(); }

void Engine::Window::swapBuffers() { glfwSwapBuffers(window); }

bool Engine::Window::shouldClose() const {
  return glfwWindowShouldClose(window);
}

void Engine::Window::setupCallbacks() {
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetWindowCloseCallback(window, window_close_callback);
}

void Engine::Window::framebuffer_size_callback(GLFWwindow *window, int width,
                                               int height) {
  if (glfwGetWindowAttrib(window, GLFW_MAXIMIZED)) {
    glViewport(0, 0, width, height);
  } else {
    glfwSetWindowSize(window, 800, 600); // default fallback
  }
}

void Engine::Window::window_close_callback(GLFWwindow* window) {
  std::print("User has clicked close button\n");
}

void Engine::Window::setIcon(const std::string &imagePath) {
  GLFWimage image;
  int channels;

  unsigned char *pixels =
      stbi_load(imagePath.c_str(), &image.width, &image.height, &channels, 4);
  if (!pixels) {
    std::println("Failed to load icon image: {}\n", imagePath);
    return;
  }

  image.pixels = pixels;

  glfwSetWindowIcon(window, 1, &image);

  stbi_image_free(pixels); // Free image memory
}
