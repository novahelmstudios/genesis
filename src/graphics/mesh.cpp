#include "graphics/mesh.hpp"
#include <glad/glad.h>

Mesh::Mesh(const std::vector<float> &vertices,
           const std::vector<unsigned int> &indices) {
  // generate VAO/VBO/EBO
}

Mesh::~Mesh() {
  // delete VAO/VBO/EBO
}

void Mesh::draw() const {
  glBindVertexArray(m_vao);
  glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
}
