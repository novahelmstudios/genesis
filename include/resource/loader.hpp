#pragma once

#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stb_image.h>

using std::cerr;
using std::ifstream;
using std::string;
using std::stringstream;

namespace Engine {

GLuint LoadTextureFromFile(const string &path);
GLuint LoadShaderFromFile(const string &vertexPath, const string &fragmentPath);

} // namespace Engine
