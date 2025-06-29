#pragma once

#include "ui/uiSystem.hpp"
#include <string>

namespace Engine {

struct lable : public UIElement {
  std::string text;

  void Draw();
};

} // namespace Engine
