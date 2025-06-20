#include "graphics/texture.hpp"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

Engine::Texture::Texture(const std::string &path) {
  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_2D, m_ID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Engine::Texture::~Texture() { glDeleteTextures(1, &m_ID); }

void Engine::Texture::bind(unsigned int unit) const {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, m_ID);
}

