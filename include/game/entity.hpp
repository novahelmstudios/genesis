#pragma once
#include "glm/glm.hpp"

class Entity {
public:
  Entity();
  virtual ~Entity();

  virtual void update(float deltaTime);
  virtual void render();

  void setPosition(const glm::vec3 &pos);

protected:
  glm::vec3 m_position;
};
