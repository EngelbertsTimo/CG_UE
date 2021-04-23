#ifndef CGTRIANGLESHAPE_H
#define CGTRIANGLESHAPE_H
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include "CgBase/CgBaseTriangleMesh.h"

class CgRotationBody: public CgBaseTriangleMesh
{
public:
  CgRotationBody(int id, int segmente, int pointNumber, std::vector<glm::vec3> workVector);
  ~CgRotationBody();

  //inherited from CgBaseRenderableObject
  Cg::ObjectType getType() const;
  unsigned int getID() const;

  void init (std::vector<glm::vec3> arg_verts, std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices);
  void init( std::string filename);

  //inherited from CgBaseTriangleMesh
  const std::vector<glm::vec3>& getVertices() const;
  const std::vector<glm::vec3>& getVertexNormals() const;
  const std::vector<glm::vec3>& getVertexColors() const;
  const std::vector<glm::vec2>& getVertexTexCoords() const;
  //const std::vector<glm::vec3>& getTriangleGravities() const;

  const std::vector<unsigned int>& getTriangleIndices() const;

  const std::vector<glm::vec3>& getFaceNormals() const;
  const std::vector<glm::vec3>& getFaceColors() const;

private:

  void createNormals();

  std::vector<glm::vec3> m_vertices;
  std::vector<glm::vec3> m_vertex_normals;
  std::vector<glm::vec3> m_vertex_colors;
  std::vector<glm::vec2> m_tex_coords;
  //std::vector<glm::vec3> m_triangle_gravities;

  std::vector<unsigned int>  m_triangle_indices;

  std::vector<glm::vec3> m_face_normals;
  std::vector<glm::vec3> m_face_colors;

  const Cg::ObjectType m_type;
  const unsigned int m_id;

};
inline Cg::ObjectType  CgRotationBody::getType() const {return m_type;}
inline unsigned int CgRotationBody::getID() const {return m_id;}

#endif // CGTRIANGLESHAPE_H

/////////////////////////////////////////////////////////
#ifndef CGTRICUBE_H
#define CGTRICUBE_H

#endif // CGTRICUBE_H
