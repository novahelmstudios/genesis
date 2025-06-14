#include "graphics/texture.hpp"
#include <glad/glad.h>
#include <stb_image.h>

Texture::Texture(const std::string& path) {
    // load texture using stb_image
}

Texture::~Texture() {
    glDeleteTextures(1, &m_id);
}

void Texture::bind(unsigned int unit) const {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

