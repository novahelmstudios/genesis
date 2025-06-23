#pragma once

#include "collider.hpp"
#include "ecs/registry.hpp"
#include "force.hpp"
#include "rigidbody.hpp"
#include "transform.hpp"

namespace Engine{

void PhysicsSystem(Engine::registry &reg, float dt);

}
