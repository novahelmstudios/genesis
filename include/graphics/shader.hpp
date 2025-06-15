#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader {
public:
  Shader(const std::string &vertexPath, const std::string &fragmentPath);
  ~Shader();

  void use() const;
  void setUniform(const std::string &name, float value) const;
  void setVec3(const std::string &name, const glm::vec3 &value) const;
  void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
  unsigned int m_ID;
};
