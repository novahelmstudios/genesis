#include "render/renderSystem.hpp"
#include "ecs/component.hpp"
#include "ecs/entity.hpp"
#include "graphics/shader.hpp"
#include "graphics/texture.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void Engine::RenderSystem::Render(Engine::registry &reg, Shader &shader) {

  shader.bind();

  auto entities = reg.View<Transform, Sprite>();
  for (auto entity : entities) {
    const auto &transform = reg.Get<Transform>(entity);
    const auto &sprite = reg.Get<Sprite>(entity);

    sprite.texture->bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(transform.position, 0.0f));
    model = glm::rotate(model, transform.rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(transform.scale, 1.0f));

    shader.setMat4("u_Model", model);
    shader.setVec4("u_Color", sprite.color);

    glBindVertexArray(sprite.vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  }
}
