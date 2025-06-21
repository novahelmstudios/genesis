#pragma once

#include <GL/gl.h>
#include <iostream>
#include <memory>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace Engine {

class ResourceManager {
public:
  static GLuint LoadTexture(const string &name, const string &path);
  static GLuint GetTexture(const string &name);

  static GLuint LoadShader(const string &name, const string &vertexPath, const string &fragmentPath);
  static GLuint GetShader(const string &name);

  /* Destroy all resources */
  static void Clear();

private:
  static unordered_map<string, GLuint> textures;
  static unordered_map<string, GLuint> shaders;
};

} // namespace Engine
