#pragma once
#include "entity.hpp"

class Player : public Entity {
public:
  Player();
  void update(float deltaTime) override;
  void render() override;
};
