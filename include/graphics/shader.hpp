#pragma once
#include <string>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;
    void setUniform(const std::string& name, float value) const;
    // Add overloads for vec3, mat4, int, etc.

private:
    unsigned int m_id;
    void compile(const std::string& src, unsigned int type);
};
