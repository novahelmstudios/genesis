#include "graphics/camera.hpp"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(float fov, float aspect, float near, float far)
    : m_fov(fov), m_aspect(aspect), m_near(near), m_far(far) {
    m_position = glm::vec3(0.0f);
    m_target = glm::vec3(0.0f, 0.0f, -1.0f);
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_target, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
}

void Camera::setPosition(const glm::vec3& pos) {
    m_position = pos;
}

void Camera::setTarget(const glm::vec3& target) {
    m_target = target;
}
