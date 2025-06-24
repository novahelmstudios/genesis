#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <memory>
#include <vector>

namespace Engine {

struct UIElement {
  glm::vec2 position;
  glm::vec2 size;
  glm::vec4 color;

  bool visible = true;
  virtual void Draw() = 0;
  virtual void Update(float dt) {}
};

class UISystem {
  std::vector<std::unique_ptr<UIElement>> elements;

public:
  void Add(std::unique_ptr<UIElement> el);
  void Draw();
  void HandleClick();
};
} // namespace Engine
