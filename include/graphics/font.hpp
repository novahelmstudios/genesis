#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>
#include <map>
#include <string>

class Shader;

struct Character {
  unsigned int textureID; /* ID of glyph texture */
  glm::ivec2 size;        /* size of glyph */
  glm::ivec2 bearing;     /* offset from baseline */
  unsigned int advance;   /* horizontal offset to advance */
};

class Font {
public:
  Font(const std::string &fontPath, unsigned int fontSize);
  ~Font();

  void renderText(Shader &shader, const std::string &text, float x, float y,
                  float scale, glm::vec3 color);
  void setProjection(const glm::mat4 &proj);

private:
  std::map<char, Character> m_Characters;
  unsigned int m_VAO, m_VBO;
  glm::mat4 m_Projection;

  void loadFont(const std::string &path, unsigned int size);
  void initBuffers();
};
