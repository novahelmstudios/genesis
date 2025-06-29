#pragma once
#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>
#include <string>

namespace Engine {

class Shader {
public:
  Shader(const std::string &vertexPath, const std::string &fragmentPath);
  ~Shader();

  void bind() const;
  void setUniform(const std::string &name, float value) const;

  void setVec3(const std::string &name, const glm::vec3 &value) const;
  void setVec4(const std::string &name, const glm::vec4 &value) const;

  void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
  void checkCompilerErorrs(unsigned int shader, std::string type);
  unsigned int m_ID;
};

} // namespace Engine
