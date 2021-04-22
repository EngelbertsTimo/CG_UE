#include "CgRotationBody.h"
#include "cgtricube.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"
#include <iostream>

CgRotationBody::CgRotationBody(int id,int segmente,int pointNumber,std::vector<glm::vec3> workVector):
  m_type(Cg::TriangleMesh),
  m_id(id)
{
  m_vertices=workVector;
  //d1
  for (int j = 0; j < segmente-1; ++j) {
      for (int i = 0; i < pointNumber-1; ++i) {
          m_triangle_indices.push_back(j*pointNumber+i+pointNumber);
          m_triangle_indices.push_back(j*pointNumber+i+1);
          m_triangle_indices.push_back(j*pointNumber+i);
        }

    }
  for (int i = 0; i < pointNumber-1; ++i) {
      m_triangle_indices.push_back(i);
      m_triangle_indices.push_back((segmente-1)*pointNumber+i+1);
      m_triangle_indices.push_back((segmente-1)*pointNumber+i);
    }


  //d2
  for (int i = 0; i < pointNumber-1; ++i) {
      m_triangle_indices.push_back(i+1);
      m_triangle_indices.push_back((segmente-1)*pointNumber+i+1);
      m_triangle_indices.push_back(i);
    }

  for (int j = 1; j < segmente; ++j) {
      for (int i = 0; i < pointNumber-1; ++i) {
          m_triangle_indices.push_back(j*pointNumber+i+1);
          m_triangle_indices.push_back(j*pointNumber+i-pointNumber+1);
          m_triangle_indices.push_back(j*pointNumber+i);
        }

    }



  //Schwerpunkte + trinangle Normal Vektoren
  double x1,x2,x3,y1,y2,y3,z1,z2,z3=0;
  for (int i = 0; i < m_triangle_indices.size(); i=i+3) {
      x1=m_vertices[m_triangle_indices[i]][0];
      y1=m_vertices[m_triangle_indices[i]][1];
      z1=m_vertices[m_triangle_indices[i]][2];

      x2=m_vertices[m_triangle_indices[i+1]][0];
      y2=m_vertices[m_triangle_indices[i+1]][1];
      z2=m_vertices[m_triangle_indices[i+1]][2];

      x3=m_vertices[m_triangle_indices[i+2]][0];
      y3=m_vertices[m_triangle_indices[i+2]][1];
      z3=m_vertices[m_triangle_indices[i+2]][2];

      m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));

      m_face_normals.push_back(normalize(glm::cross(m_vertices[m_triangle_indices[i]]-m_vertices[m_triangle_indices[i+1]],m_vertices[m_triangle_indices[i]]-m_vertices[m_triangle_indices[i+2]])));
    }

  //vertex Normal Vektoren
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
              //std::cout << "CgRotationBody: vertex nummer "<<j<<" gefunden an pos "<<i <<std::endl;

              int dreieck = floor(i/3);
              // std::cout << "CgRotationBody: vertex nummer "<<j<<" teil von dreieck an pos "<<dreieck <<std::endl;
              workVec=workVec+m_face_normals[dreieck];
              zaeler++;
              x_vec.push_back(m_face_normals[dreieck][0]);
              y_vec.push_back(m_face_normals[dreieck][1]);
              z_vec.push_back(m_face_normals[dreieck][2]);

              x=x+(m_face_normals[dreieck][0]);
              y=y+(m_face_normals[dreieck][1]);
              z=z+(m_face_normals[dreieck][2]);
              std::cout << "CgRotationBody: m_face_normals "<<j <<"; x= "<<m_face_normals[dreieck][0]<<"; y= "<<m_face_normals[dreieck][1]<<"; z= "<<m_face_normals[dreieck][2]<<std::endl;
              std::cout << "CgRotationBody: zusatzVectors  "<<j <<"; x= "<<x_vec[zaeler]<<"; y= "<<y_vec[zaeler]<<"; z= "<<z_vec[zaeler]<<"; zähler = "<<zaeler<<std::endl;
              std::cout << "CgRotationBody: workVec        "<<j <<"; x= "<<workVec[0]<<"; y= "<<workVec[1]<<"; z= "<<workVec[2]<<std::endl;
              std::cout << "CgRotationBody: aufzählen      "<<j <<"; x= "<<x<<"; y= "<<x<<"; z= "<<z<<std::endl<<std::endl;

            }
        }
     x=x/zaeler;
     y=y/zaeler;
     z=z/zaeler;

      m_vertex_normals.push_back(normalize(glm::vec3(x,y,z)));
    }
}

CgRotationBody::~CgRotationBody()
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_vertex_colors.clear();
  m_tex_coords.clear();
  m_triangle_indices.clear();
  m_face_normals.clear();
  m_face_colors.clear();
}

void CgRotationBody::init( std::vector<glm::vec3> arg_verts,  std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices)
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_triangle_indices.clear();
  m_vertices=arg_verts;
  m_vertex_normals=arg_normals;
  m_triangle_indices=arg_triangle_indices;
}

void CgRotationBody::init( std::string filename)
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


const std::vector<glm::vec3>& CgRotationBody::getVertices() const
{
  return m_vertices;
}

const std::vector<glm::vec3>& CgRotationBody::getVertexNormals() const
{
  return m_vertex_normals;
}

const std::vector<glm::vec3>& CgRotationBody::getVertexColors() const
{
  return m_vertex_colors;
}

const std::vector<glm::vec2>& CgRotationBody:: getVertexTexCoords() const
{
  return m_tex_coords;
}

const std::vector<unsigned int>& CgRotationBody::getTriangleIndices() const
{
  return m_triangle_indices;
}

const std::vector<glm::vec3>& CgRotationBody::getFaceNormals() const
{
  return m_face_normals;
}

const std::vector<glm::vec3>& CgRotationBody::getTriangleGravities() const
{
  return m_triangle_gravities;
}

const std::vector<glm::vec3>& CgRotationBody::getFaceColors() const
{
  return m_face_colors;
}

