#pragma once
#include <string>

class Texture {
public:
  Texture(const std::string &path);
  ~Texture();

  void bind(unsigned int unit = 0) const;

private:
  unsigned int m_ID;
};
