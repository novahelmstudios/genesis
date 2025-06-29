#include "core/time.hpp"
#include <GLFW/glfw3.h>

float Time::s_lastTime = 0.0f;
float Time::s_deltaTime = 0.0f;

float Time::getDeltaTime() {
    return s_deltaTime;
}

void Time::update() {
    float current = glfwGetTime();
    s_deltaTime = current - s_lastTime;
    s_lastTime = current;
}

