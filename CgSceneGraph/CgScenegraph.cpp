#include "CgScenegraph.h"


CgScenegraphEnity *CgScenegraph::root_node() const
{
  return m_root_node;
}

void CgScenegraph::setRoot_node(CgScenegraphEnity *root_node)
{
  m_root_node = root_node;
}

std::stack<glm::mat4> CgScenegraph::modelview_matrix_stack() const
{
  return m_modelview_matrix_stack;
}

void CgScenegraph::setModelview_matrix_stack(const std::stack<glm::mat4> &modelview_matrix_stack)
{
  m_modelview_matrix_stack = modelview_matrix_stack;
}

void CgScenegraph::render(CgBaseRenderer* renderer){

  std::vector<CgBaseRenderableObject *> renderObjects = m_root_node->getList_of_Objects();

  for (int i = 0; i < renderObjects.size(); ++i) {
      renderer->init(renderObjects[i]);
      renderer->render(renderObjects[i]);
    }


}
