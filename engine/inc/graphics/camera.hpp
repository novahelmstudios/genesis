#pragma once
#include <glm/glm.hpp>

namespace Engine {

class Camera {
public:
  Camera(float fov, float aspect, float near, float far);

  glm::mat4 getViewMatrix() const;
  glm::mat4 getProjectionMatrix() const;

  void setPosition(const glm::vec3 &pos);
  void setTarget(const glm::vec3 &target);

private:
  glm::vec3 m_position;
  glm::vec3 m_target;
  float m_fov, m_aspect, m_near, m_far;
};

} // namespace Engine
