#include "core/application.hpp"
#include <iostream>

int main() {
  try {
    Application app(1280, 720, "OpenGL Game");
    app.run();
  } catch (const std::exception &e) {
    std::cerr << "Fatal error: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
