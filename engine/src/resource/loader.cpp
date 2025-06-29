#include "resource/loader.hpp"

/*
 * Loading textures
 */
GLuint Engine::LoadTextureFromFile(const string &path) {
  int width, height, channels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 4);

  if (!data) {
    cerr << "Failed to load Texture\n Failed: ResourceManager \nFile: " << path
         << '\n';
    return 0;
  }

  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexImage2D(GL_TEXTURE_2D,    /*     GLenum target    */
               0,                /*      GLint level     */
               GL_RGBA,          /* GLint internalFormat */
               width,            /*     GLsizei width    */
               height,           /*     GLsizei height   */
               0,                /*      GLint border    */
               GL_RGBA,          /*      GLenum format   */
               GL_UNSIGNED_BYTE, /*       GLenum type    */
               data              /* const GLvoid *pixels */
  );

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBindTexture(GL_TEXTURE_2D, 0);
  stbi_image_free(data);

  return texture;
}

/*
 * Loading shaders
 */

GLuint compileShader(GLenum type, const string &source) {
  GLuint shader = glCreateShader(type);
  const char *src = source.c_str();
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  GLint success = 0;

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    char log[512];
    glGetShaderInfoLog(shader, 512, nullptr, log);
    cerr << "Shader Compile error: \n" << log << '\n';
  }

  return shader;
}

string readShader(const string &path) {
  ifstream file(path);
  stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

GLuint Engine::LoadShaderFromFile(const string &vertexPath,
                                  const string &fragmentPath) {
  string vertexCode = readShader(vertexPath);
  string fragmentCode = readShader(fragmentPath);

  GLuint vert = compileShader(GL_VERTEX_SHADER, vertexCode);
  GLuint frag = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

  GLuint prog = glCreateProgram();
  glAttachShader(prog, vert);
  glAttachShader(prog, frag);
  glLinkProgram(prog);

  GLint success;
  glGetProgramiv(prog, GL_LINK_STATUS, &success);

  if (!success) {
    char log[512];
    glGetProgramInfoLog(prog, 512, nullptr, log);
    cerr << "Shader link error:\n" << log << "\n";
  }

  glDeleteShader(vert);
  glDeleteShader(frag);

  return prog;
}
