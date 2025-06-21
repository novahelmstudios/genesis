#include "graphics/shader.hpp"
#include "glad/glad.h"
#include <fstream>
#include <iostream>
#include <sstream>

Engine::Shader::Shader(const std::string &vertexPath,
                       const std::string &fragmentPath) {
  std::ifstream vfile(vertexPath), ffile(fragmentPath);
  std::stringstream vstream, fstream;

  vstream << vfile.rdbuf();
  fstream << ffile.rdbuf();

  std::string vcode = vstream.str();
  std::string fcode = fstream.str();

  const char *vsrc = vcode.c_str();
  const char *fsrc = fcode.c_str();

  unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vsrc, nullptr);
  glCompileShader(vertex);
  checkCompilerErorrs(m_ID, "VERTEX");

  unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fsrc, nullptr);
  glCompileShader(fragment);
  checkCompilerErorrs(m_ID, "FRAGMENT");

  m_ID = glCreateProgram();
  glAttachShader(m_ID, vertex);
  glAttachShader(m_ID, fragment);
  glLinkProgram(m_ID);
  checkCompilerErorrs(m_ID, "PROGRAM");

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

Engine::Shader::~Shader() { glDeleteProgram(m_ID); }

void Engine::Shader::bind() const { glUseProgram(m_ID); }

void Engine::Shader::setUniform(const std::string &name, float value) const {
  int loc = glGetUniformLocation(m_ID, name.c_str());
  glUniform1f(loc, value);
}

void Engine::Shader::setVec3(const std::string &name,
                             const glm::vec3 &value) const {
  glUniform3f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y,
              value.z);
}

void Engine::Shader::setVec4(const std::string &name,
                             const glm::vec4 &value) const {
    GLint location = glGetUniformLocation(m_ID, name.c_str());
    glUniform4fv(location, 1, &value[0]);
}

void Engine::Shader::setMat4(const std::string &name,
                             const glm::mat4 &mat) const {
  glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE,
                     &mat[0][0]);
}

void Engine::Shader::checkCompilerErorrs(unsigned int shader,
                                         std::string type) {
  int success;
  char infoLog[1024];
  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                << infoLog << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                << infoLog << std::endl;
    }
  }
}
