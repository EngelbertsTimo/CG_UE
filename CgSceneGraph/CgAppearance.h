#ifndef CGAPPEARANCE_H
#define CGAPPEARANCE_H
#include <glm/glm.hpp>

class CgAppearance
{

private:
  CgAppearance();
  glm::vec3 object_color;
  glm::vec3 diffuse_material;


public:
  glm::vec3 getDiffuse_material() const;
  void setDiffuse_material(const glm::vec3 &value);
  glm::vec3 getObject_color() const;
  void setObject_color(const glm::vec3 &value);
};

#endif // CGAPPEARANCE_H
