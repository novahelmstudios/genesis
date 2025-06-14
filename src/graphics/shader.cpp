#include "graphics/shader.hpp"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    // load and compile shader here
}

Shader::~Shader() {
    glDeleteProgram(m_id);
}

void Shader::use() const {
    glUseProgram(m_id);
}

void Shader::setUniform(const std::string& name, float value) const {
    int loc = glGetUniformLocation(m_id, name.c_str());
    glUniform1f(loc, value);
}

