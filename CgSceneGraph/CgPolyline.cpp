#include "CgPolyline.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"

CgPolyline::CgPolyline():
  m_type(Cg::Polyline),
   m_id(40)
{
  m_vertices.push_back(glm::vec3(-0.0,0.0,0.0));
  m_vertices.push_back(glm::vec3(5.5,-0.5,0.0));
  /*m_vertices.push_back(glm::vec3(0.0,0.5,0.0));
   m_vertices.push_back(glm::vec3(0.0,0.5,0.5));*/



  m_lineWidth =1;

}

CgPolyline::CgPolyline(int id,glm::vec3 startPoint,glm::vec3 direction):
  m_type(Cg::Polyline),
   m_id(id)
{
  glm::vec3 endPoint = startPoint+direction;
  m_vertices.push_back(startPoint);
  m_vertices.push_back(endPoint);
  /*m_vertices.push_back(glm::vec3(0.0,0.5,0.0));
   m_vertices.push_back(glm::vec3(0.0,0.5,0.5));*/



  m_lineWidth =1;

}

CgPolyline::CgPolyline(int id,std::vector<glm::vec3> vectors):
  m_type(Cg::Polyline),
   m_id(id)
{
  for(int i=0;i<vectors.size();i++){
       m_vertices.push_back(vectors[i]);
    }



  m_lineWidth =1;

}


CgPolyline::~CgPolyline()
{
  m_vertices.clear();
  m_triangle_indices.clear();
}

void CgPolyline::init( std::vector<glm::vec3> arg_verts, std::vector<unsigned int> arg_triangle_indices)
{
    m_vertices.clear();

    m_triangle_indices.clear();
    m_vertices=arg_verts;

    m_triangle_indices=arg_triangle_indices;
}

void CgPolyline::init( std::string filename)
{
    m_vertices.clear();
    m_triangle_indices.clear();

    ObjLoader loader;
    loader.load(filename);

    loader.getPositionData(m_vertices);

    loader.getFaceIndexData(m_triangle_indices);
}

const std::vector<glm::vec3>& CgPolyline::getVertices() const
{
    return m_vertices;
}

glm::vec3 CgPolyline::getColor() const{
  return m_color;
}
unsigned int CgPolyline::getLineWidth() const{
  return m_lineWidth;
}

Cg::ObjectType CgPolyline::getType() const{
  return m_type;
}
unsigned int CgPolyline::getID() const{
  return m_id;
}

