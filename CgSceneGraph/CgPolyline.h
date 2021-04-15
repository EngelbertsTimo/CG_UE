#ifndef CGPOLYLINE_H
#define CGPOLYLINE_H

#include <vector>
#include <glm/glm.hpp>
#include <string>
#include "CgBase/CgBasePolyline.h"

class CgPolyline : public CgBasePolyline
{
public:
  CgPolyline();
  CgPolyline(int id,glm::vec3 startPoint,glm::vec3 direction);
  ~CgPolyline();

  //inherited from CgBaseRenderableObject
  Cg::ObjectType getType() const;
  unsigned int getID() const;

  void init (std::vector<glm::vec3> arg_verts, std::vector<unsigned int> arg_triangle_indices);
  void init( std::string filename);

  // inherited
  const std::vector<glm::vec3>& getVertices() const;
  glm::vec3 getColor() const;
  unsigned int getLineWidth() const;


private:
    std::vector<glm::vec3> m_vertices;
    std::vector<unsigned int>  m_triangle_indices;
    const Cg::ObjectType m_type;
    unsigned int m_lineWidth;
      unsigned int m_id;
    glm::vec3 m_color;
};

#endif // CGPOLYLINE_H
