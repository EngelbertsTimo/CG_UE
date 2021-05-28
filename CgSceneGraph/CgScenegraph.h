#ifndef CGSCENEGRAPH_H
#define CGSCENEGRAPH_H

#import "CgBase/CgBaseRenderer.h"
#import "CgScenegraphEnity.h"
#include <stack>
#include <glm/glm.hpp>

class CgScenegraph
{
private:
  CgScenegraphEnity* m_root_node;
  std::stack <glm::mat4> m_modelview_matrix_stack;

  void pushMatrix() {m_modelview_matrix_stack.push(m_modelview_matrix_stack.top());}
  void popMatrix() {m_modelview_matrix_stack.pop();}
  void applyTransform(glm::mat4 arg) {m_modelview_matrix_stack.top()*=arg;}

public:
  void render(CgBaseRenderer* renderer);
  std::stack<glm::mat4> modelview_matrix_stack() const;
  void setModelview_matrix_stack(const std::stack<glm::mat4> &modelview_matrix_stack);
  CgScenegraphEnity *root_node() const;
  void setRoot_node(CgScenegraphEnity *root_node);
};

#endif // CGSCENEGRAPH_H
