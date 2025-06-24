#pragma once

#include "ui/uiSystem.hpp"

#include <functional>
#include <string>

namespace Engine {


struct Button: public UIElement{
    std::string text;
    std::function<void()> onClick;

    void Draw();

    void HandleClick();
};

}
