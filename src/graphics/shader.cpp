#include "graphics/shader.hpp"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::ifstream vfile(vertexPath), ffile(fragmentPath);
    std:: stringstream vstream, fstream;

    vstream << vfile.rdbuf();
    fstream << ffile.rdbuf();

    std:: string vcode = vstream.str();
    std:: string fcode = fstream.str();

    const char* vsrc = vcode.c_str();
    const char* fsrc = fcode.c_str();

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vsrc, nullptr);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fsrc, nullptr);
    glCompileShader(fragment);

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertex);
    glAttachShader(m_ID, fragment);
    glLinkProgram(m_ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(m_ID);
}

void Shader::use() const {
    glUseProgram(m_ID);
}

void Shader::setUniform(const std::string& name, float value) const {
    int loc = glGetUniformLocation(m_ID, name.c_str());
    glUniform1f(loc, value);
}


void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
    glUniform3f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y, value.z);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

