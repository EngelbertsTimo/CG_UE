#include "CgScenegraphEnity.h"

std::vector<CgBaseRenderableObject *> CgScenegraphEnity::getList_of_Objects() const
{
  return list_of_Objects;
}

void CgScenegraphEnity::setList_of_Objects(const std::vector<CgBaseRenderableObject *> &value)
{
  list_of_Objects = value;
}

glm::mat4 CgScenegraphEnity::getCurrent_transformation() const
{
  return m_current_transformation;
}

void CgScenegraphEnity::setCurrent_transformation(const glm::mat4 &current_transformation)
{
  m_current_transformation = current_transformation;
}

CgAppearance CgScenegraphEnity::getApperance() const
{
  return m_apperance;
}

void CgScenegraphEnity::setApperance(const CgAppearance &apperance)
{
  m_apperance = apperance;
}

CgScenegraphEnity *CgScenegraphEnity::getParent() const
{
  return m_parent;
}

void CgScenegraphEnity::setParent(CgScenegraphEnity *parent)
{
  m_parent = parent;
}

std::vector<CgScenegraphEnity *> CgScenegraphEnity::getChildren() const
{
  return m_children;
}

void CgScenegraphEnity::setChildren(const std::vector<CgScenegraphEnity *> &children)
{
  m_children = children;
}

CgScenegraphEnity::CgScenegraphEnity()
{

}
