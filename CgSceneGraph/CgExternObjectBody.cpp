#include "CgExternObjectBody.h"
#include "cgtricube.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"
#include <iostream>

CgExternObjectBody::CgExternObjectBody(int id,std::string filename):
  m_type(Cg::TriangleMesh),
  m_id(id)
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_triangle_indices.clear();

  ObjLoader loader;
  loader.load(filename);

  loader.getPositionData(m_vertices);
  //loader.getNormalData(m_vertex_normals);
  loader.getFaceIndexData(m_triangle_indices);

  createNormals();
}
void CgExternObjectBody::createNormals(){
  for (int i = 0; i < m_triangle_indices.size(); i=i+3) {
      m_face_normals.push_back(normalize(glm::cross(m_vertices[m_triangle_indices[i]]-m_vertices[m_triangle_indices[i+1]],m_vertices[m_triangle_indices[i]]-m_vertices[m_triangle_indices[i+2]])));
    }

  glm::vec3 workVec=glm::vec3(0.0,0.0,0.0);
  std::vector<double> x_vec,y_vec,z_vec;
  double x,y,z;
  int zaeler;
  for (int j = 0; j < m_vertices.size(); ++j) {
      workVec=glm::vec3(0.0,0.0,0.0);
      z=0;
      x=0;
      y=0;
      zaeler=0;
      for (int i = 0; i < m_triangle_indices.size(); i++) {
          if(j==m_triangle_indices[i]){
              int dreieck = floor(i/3);

              workVec=workVec+m_face_normals[dreieck];
              zaeler++;
              x_vec.push_back(m_face_normals[dreieck][0]);
              y_vec.push_back(m_face_normals[dreieck][1]);
              z_vec.push_back(m_face_normals[dreieck][2]);

              x=x+(m_face_normals[dreieck][0]);
              y=y+(m_face_normals[dreieck][1]);
              z=z+(m_face_normals[dreieck][2]);
            }
        }
      x=x/zaeler;
      y=y/zaeler;
      z=z/zaeler;

      m_vertex_normals.push_back(normalize(glm::vec3(x,y,z)));
    }
}


CgExternObjectBody::~CgExternObjectBody()
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_vertex_colors.clear();
  m_tex_coords.clear();
  m_triangle_indices.clear();
  m_face_normals.clear();
  m_face_colors.clear();
}

void CgExternObjectBody::init( std::vector<glm::vec3> arg_verts,  std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices)
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_triangle_indices.clear();
  m_vertices=arg_verts;
  m_vertex_normals=arg_normals;
  m_triangle_indices=arg_triangle_indices;
}

void CgExternObjectBody::init( std::string filename)
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_triangle_indices.clear();

  ObjLoader loader;
  loader.load(filename);

  loader.getPositionData(m_vertices);
  loader.getNormalData(m_vertex_normals);
  loader.getFaceIndexData(m_triangle_indices);
}


const std::vector<glm::vec3>& CgExternObjectBody::getVertices() const
{
  return m_vertices;
}

const std::vector<glm::vec3>& CgExternObjectBody::getVertexNormals() const
{
  return m_vertex_normals;
}

const std::vector<glm::vec3>& CgExternObjectBody::getVertexColors() const
{
  return m_vertex_colors;
}

const std::vector<glm::vec2>& CgExternObjectBody:: getVertexTexCoords() const
{
  return m_tex_coords;
}

const std::vector<unsigned int>& CgExternObjectBody::getTriangleIndices() const
{
  return m_triangle_indices;
}

const std::vector<glm::vec3>& CgExternObjectBody::getFaceNormals() const
{
  return m_face_normals;
}

const std::vector<glm::vec3>& CgExternObjectBody::getFaceColors() const
{
  return m_face_colors;
}

