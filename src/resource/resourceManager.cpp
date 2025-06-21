#include "resource/loader.hpp"
#include "resource/resourceManager.hpp"

unordered_map<string, GLuint> Engine::ResourceManager::textures;
unordered_map<string, GLuint> Engine::ResourceManager::shaders;

/*
 * Loads a texture from file (if not already loaded), uploads it to the GPU,
 * caches it under the given name, and returns the OpenGL texture ID.
 *
 * GLuint playerTex = Engine::ResourceManager::LoadTexture("player", "assets/player.png");
 * reg.Add<SpriteSheet>(e, "player", playerTex, ...);
 */
GLuint Engine::ResourceManager::LoadTexture(const string &name,
                                            const string &path) {
  if (textures.count(name))
    return textures[name];

  GLuint tex = LoadTextureFromFile(path);
  textures[name] = tex;
  return tex;
}

GLuint Engine::ResourceManager::GetTexture(const string &name) {
  return textures.at(name);
}


/*
 * Loads and compiles vertex and fragment shaders, links them into a shader program,
 * caches the result under the given name.
 *
 * GLuint shader = Engine::ResourceManager::LoadShader("sprite",
 *                                                     "assets/shaders/sprite.vert",
 *                                                     "assets/shaders/sprite.frag");
 */
GLuint Engine::ResourceManager::LoadShader(const string &name,
                                           const string &vertexPath,
                                           const string &fragmentPath) {
  if (shaders.count(name))
    return shaders[name];

  GLuint shader = LoadShaderFromFile(vertexPath, fragmentPath);
  shaders[name] = shader;
  return shader;
}

GLuint Engine::ResourceManager::GetShader(const string &name) {
  return shaders.at(name);
}

void Engine::ResourceManager::Clear() {
  for (auto &[_, tex] : textures)
    glDeleteTextures(1, &tex);
  for (auto &[_, sh] : shaders)
    glDeleteTextures(1, &sh);
}
