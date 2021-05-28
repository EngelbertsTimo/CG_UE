#include "CgAppearance.h"

CgAppearance::CgAppearance()
{

}

glm::vec3 CgAppearance::getDiffuse_material() const
{
  return diffuse_material;
}

void CgAppearance::setDiffuse_material(const glm::vec3 &value)
{
  diffuse_material = value;
}

glm::vec3 CgAppearance::getObject_color() const
{
  return object_color;
}

void CgAppearance::setObject_color(const glm::vec3 &value)
{
  object_color = value;
}
