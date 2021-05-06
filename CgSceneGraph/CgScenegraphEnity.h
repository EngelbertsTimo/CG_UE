#ifndef CGSCENEGRAPHENITY_H
#define CGSCENEGRAPHENITY_H
#include <vector>
#include <glm/glm.hpp>
#include <CgBase/CgBaseRenderableObject.h>
#include <CgSceneGraph/CgAppearance.h>
class CgScenegraphEnity
{

private:
  std::vector<CgBaseRenderableObject*> list_of_Objects;
  glm::mat4 m_current_transformation;

  CgAppearance m_apperance;

  CgScenegraphEnity* m_parent;
  std::vector<CgScenegraphEnity*> m_children;

public:
  CgScenegraphEnity();
  std::vector<CgBaseRenderableObject *> getList_of_Objects() const;
  void setList_of_Objects(const std::vector<CgBaseRenderableObject *> &value);
  glm::mat4 getCurrent_transformation() const;
  void setCurrent_transformation(const glm::mat4 &current_transformation);
  CgAppearance getApperance() const;
  void setApperance(const CgAppearance &apperance);
  CgScenegraphEnity *getParent() const;
  void setParent(CgScenegraphEnity *parent);
  std::vector<CgScenegraphEnity *> getChildren() const;
  void setChildren(const std::vector<CgScenegraphEnity *> &children);
};

#endif // CGSCENEGRAPHENITY_H
