#include "cgtricube.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"
#include <iostream>

CgTriCube::CgTriCube():
  m_type(Cg::TriangleMesh),
  m_id(42)
{
  std::cout << "CgTriCube.cpp: erstellt" <<std::endl;

  m_vertices.push_back(glm::vec3(-0.5,0.0,-0.35));
  m_vertices.push_back(glm::vec3(0.0,-0.5,-0.35));
  m_vertices.push_back(glm::vec3(0.0,0.5,-0.35));
  m_vertices.push_back(glm::vec3(0.5,0.0,-0.35));

  m_vertices.push_back(glm::vec3(-0.5,0.0,0.35));
  m_vertices.push_back(glm::vec3(0.0,-0.5,0.35));
  m_vertices.push_back(glm::vec3(0.0,0.5,0.35));
  m_vertices.push_back(glm::vec3(0.5,0.0,0.35));

  //Boden
  //  dreieck 1
  m_triangle_indices.push_back(0);
  m_triangle_indices.push_back(2);
  m_triangle_indices.push_back(1);

  //  dreieck 2
  m_triangle_indices.push_back(1);
  m_triangle_indices.push_back(2);
  m_triangle_indices.push_back(3);

  //S1
  //  dreieck 3
  m_triangle_indices.push_back(0);
  m_triangle_indices.push_back(5);
  m_triangle_indices.push_back(4);

  //  dreieck 4
  m_triangle_indices.push_back(0);
  m_triangle_indices.push_back(1);
  m_triangle_indices.push_back(5);

  //S2
  //  dreieck 5
  m_triangle_indices.push_back(0);
  m_triangle_indices.push_back(4);
  m_triangle_indices.push_back(2);

  //  dreieck 6
  m_triangle_indices.push_back(2);
  m_triangle_indices.push_back(4);
  m_triangle_indices.push_back(6);

  //S3
  //  dreieck 7
  m_triangle_indices.push_back(2);
  m_triangle_indices.push_back(6);
  m_triangle_indices.push_back(3);

  //  dreieck 8
  m_triangle_indices.push_back(3);
  m_triangle_indices.push_back(6);
  m_triangle_indices.push_back(7);

  //S4
  //  dreieck 9
  m_triangle_indices.push_back(1);
  m_triangle_indices.push_back(3);
  m_triangle_indices.push_back(5);

  //  dreieck 10
  m_triangle_indices.push_back(3);
  m_triangle_indices.push_back(7);
  m_triangle_indices.push_back(5);

  //Decke
  //  dreieck 11
  m_triangle_indices.push_back(4);
  m_triangle_indices.push_back(5);
  m_triangle_indices.push_back(6);

  //  dreieck 12
  m_triangle_indices.push_back(6);
  m_triangle_indices.push_back(5);
  m_triangle_indices.push_back(7);

  double x1,x2,x3,y1,y2,y3,z1,z2,z3=0;



  //Schwerpunkte

  //  dreieck 1   0-2
  x1=m_vertices[m_triangle_indices[0]][0];
  y1=m_vertices[m_triangle_indices[0]][1];
  z1=m_vertices[m_triangle_indices[0]][2];

  x2=m_vertices[m_triangle_indices[1]][0];
  y2=m_vertices[m_triangle_indices[1]][1];
  z2=m_vertices[m_triangle_indices[1]][2];

  x3=m_vertices[m_triangle_indices[2]][0];
  y3=m_vertices[m_triangle_indices[2]][1];
  z3=m_vertices[m_triangle_indices[2]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));

  //  dreieck 2   3-5
  x1=m_vertices[m_triangle_indices[3]][0];
  y1=m_vertices[m_triangle_indices[3]][1];
  z1=m_vertices[m_triangle_indices[3]][2];

  x2=m_vertices[m_triangle_indices[4]][0];
  y2=m_vertices[m_triangle_indices[4]][1];
  z2=m_vertices[m_triangle_indices[4]][2];

  x3=m_vertices[m_triangle_indices[5]][0];
  y3=m_vertices[m_triangle_indices[5]][1];
  z3=m_vertices[m_triangle_indices[5]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 3   6-8
  x1=m_vertices[m_triangle_indices[6]][0];
  y1=m_vertices[m_triangle_indices[6]][1];
  z1=m_vertices[m_triangle_indices[6]][2];

  x2=m_vertices[m_triangle_indices[7]][0];
  y2=m_vertices[m_triangle_indices[7]][1];
  z2=m_vertices[m_triangle_indices[7]][2];

  x3=m_vertices[m_triangle_indices[8]][0];
  y3=m_vertices[m_triangle_indices[8]][1];
  z3=m_vertices[m_triangle_indices[8]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 4   9-11
  x1=m_vertices[m_triangle_indices[9]][0];
  y1=m_vertices[m_triangle_indices[9]][1];
  z1=m_vertices[m_triangle_indices[9]][2];

  x2=m_vertices[m_triangle_indices[10]][0];
  y2=m_vertices[m_triangle_indices[10]][1];
  z2=m_vertices[m_triangle_indices[10]][2];

  x3=m_vertices[m_triangle_indices[11]][0];
  y3=m_vertices[m_triangle_indices[11]][1];
  z3=m_vertices[m_triangle_indices[11]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 5   12-14
  x1=m_vertices[m_triangle_indices[12]][0];
  y1=m_vertices[m_triangle_indices[12]][1];
  z1=m_vertices[m_triangle_indices[12]][2];

  x2=m_vertices[m_triangle_indices[13]][0];
  y2=m_vertices[m_triangle_indices[13]][1];
  z2=m_vertices[m_triangle_indices[13]][2];

  x3=m_vertices[m_triangle_indices[14]][0];
  y3=m_vertices[m_triangle_indices[14]][1];
  z3=m_vertices[m_triangle_indices[14]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 6   15-17
  x1=m_vertices[m_triangle_indices[15]][0];
  y1=m_vertices[m_triangle_indices[15]][1];
  z1=m_vertices[m_triangle_indices[15]][2];

  x2=m_vertices[m_triangle_indices[16]][0];
  y2=m_vertices[m_triangle_indices[16]][1];
  z2=m_vertices[m_triangle_indices[16]][2];

  x3=m_vertices[m_triangle_indices[17]][0];
  y3=m_vertices[m_triangle_indices[17]][1];
  z3=m_vertices[m_triangle_indices[17]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 7   18-20
  x1=m_vertices[m_triangle_indices[18]][0];
  y1=m_vertices[m_triangle_indices[18]][1];
  z1=m_vertices[m_triangle_indices[18]][2];

  x2=m_vertices[m_triangle_indices[19]][0];
  y2=m_vertices[m_triangle_indices[19]][1];
  z2=m_vertices[m_triangle_indices[19]][2];

  x3=m_vertices[m_triangle_indices[20]][0];
  y3=m_vertices[m_triangle_indices[20]][1];
  z3=m_vertices[m_triangle_indices[20]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 8   21-23
  x1=m_vertices[m_triangle_indices[21]][0];
  y1=m_vertices[m_triangle_indices[21]][1];
  z1=m_vertices[m_triangle_indices[21]][2];

  x2=m_vertices[m_triangle_indices[22]][0];
  y2=m_vertices[m_triangle_indices[22]][1];
  z2=m_vertices[m_triangle_indices[22]][2];

  x3=m_vertices[m_triangle_indices[23]][0];
  y3=m_vertices[m_triangle_indices[23]][1];
  z3=m_vertices[m_triangle_indices[23]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 9   24-26
  x1=m_vertices[m_triangle_indices[24]][0];
  y1=m_vertices[m_triangle_indices[24]][1];
  z1=m_vertices[m_triangle_indices[24]][2];

  x2=m_vertices[m_triangle_indices[25]][0];
  y2=m_vertices[m_triangle_indices[25]][1];
  z2=m_vertices[m_triangle_indices[25]][2];

  x3=m_vertices[m_triangle_indices[26]][0];
  y3=m_vertices[m_triangle_indices[26]][1];
  z3=m_vertices[m_triangle_indices[26]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 10  27-29
  x1=m_vertices[m_triangle_indices[27]][0];
  y1=m_vertices[m_triangle_indices[27]][1];
  z1=m_vertices[m_triangle_indices[27]][2];

  x2=m_vertices[m_triangle_indices[28]][0];
  y2=m_vertices[m_triangle_indices[28]][1];
  z2=m_vertices[m_triangle_indices[28]][2];

  x3=m_vertices[m_triangle_indices[29]][0];
  y3=m_vertices[m_triangle_indices[29]][1];
  z3=m_vertices[m_triangle_indices[29]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 11  30-32
  x1=m_vertices[m_triangle_indices[30]][0];
  y1=m_vertices[m_triangle_indices[30]][1];
  z1=m_vertices[m_triangle_indices[30]][2];

  x2=m_vertices[m_triangle_indices[31]][0];
  y2=m_vertices[m_triangle_indices[31]][1];
  z2=m_vertices[m_triangle_indices[31]][2];

  x3=m_vertices[m_triangle_indices[32]][0];
  y3=m_vertices[m_triangle_indices[32]][1];
  z3=m_vertices[m_triangle_indices[32]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //  dreieck 12  33-35
  x1=m_vertices[m_triangle_indices[33]][0];
  y1=m_vertices[m_triangle_indices[33]][1];
  z1=m_vertices[m_triangle_indices[33]][2];

  x2=m_vertices[m_triangle_indices[34]][0];
  y2=m_vertices[m_triangle_indices[34]][1];
  z2=m_vertices[m_triangle_indices[34]][2];

  x3=m_vertices[m_triangle_indices[35]][0];
  y3=m_vertices[m_triangle_indices[35]][1];
  z3=m_vertices[m_triangle_indices[35]][2];

  m_triangle_gravities.push_back(glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)));


  //Dreieck Normale

  //  dreieck 1   0-2
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[0]]-m_vertices[m_triangle_indices[1]],m_vertices[m_triangle_indices[0]]-m_vertices[m_triangle_indices[2]]));

  //  dreieck 2   3-5
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[3]]-m_vertices[m_triangle_indices[4]],m_vertices[m_triangle_indices[3]]-m_vertices[m_triangle_indices[5]]));

  //  dreieck 3   6-8
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[6]]-m_vertices[m_triangle_indices[7]],m_vertices[m_triangle_indices[6]]-m_vertices[m_triangle_indices[8]]));

  //  dreieck 4   9-11
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[9]]-m_vertices[m_triangle_indices[10]],m_vertices[m_triangle_indices[9]]-m_vertices[m_triangle_indices[11]]));

  //  dreieck 5   12-14
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[12]]-m_vertices[m_triangle_indices[13]],m_vertices[m_triangle_indices[12]]-m_vertices[m_triangle_indices[14]]));

  //  dreieck 6   15-17
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[15]]-m_vertices[m_triangle_indices[16]],m_vertices[m_triangle_indices[15]]-m_vertices[m_triangle_indices[17]]));

  //  dreieck 7   18-20
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[18]]-m_vertices[m_triangle_indices[19]],m_vertices[m_triangle_indices[18]]-m_vertices[m_triangle_indices[20]]));

  //  dreieck 8   21-23
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[21]]-m_vertices[m_triangle_indices[22]],m_vertices[m_triangle_indices[21]]-m_vertices[m_triangle_indices[23]]));

  //  dreieck 9   24-26
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[24]]-m_vertices[m_triangle_indices[25]],m_vertices[m_triangle_indices[24]]-m_vertices[m_triangle_indices[26]]));

  //  dreieck 10  27-29
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[27]]-m_vertices[m_triangle_indices[28]],m_vertices[m_triangle_indices[27]]-m_vertices[m_triangle_indices[29]]));

  //  dreieck 11  30-31
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[30]]-m_vertices[m_triangle_indices[31]],m_vertices[m_triangle_indices[30]]-m_vertices[m_triangle_indices[32]]));

  //  dreieck 12  33-35
  m_vertex_normals.push_back(glm::cross(m_vertices[m_triangle_indices[33]]-m_vertices[m_triangle_indices[34]],m_vertices[m_triangle_indices[33]]-m_vertices[m_triangle_indices[35]]));


  /*std::cout << "CgTriCube.cpp: punkte"<< <<std::endl;
  std::cout << "CgTriCube.cpp: schwerpunkt"<< <<std::endl;
  std::cout << "CgTriCube.cpp: normal vektor"<< <<std::endl;*/

}

CgTriCube::~CgTriCube()
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_vertex_colors.clear();
  m_tex_coords.clear();
  m_triangle_indices.clear();
  m_face_normals.clear();
  m_face_colors.clear();
}

void CgTriCube::init( std::vector<glm::vec3> arg_verts,  std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices)
{
  m_vertices.clear();
  m_vertex_normals.clear();
  m_triangle_indices.clear();
  m_vertices=arg_verts;
  m_vertex_normals=arg_normals;
  m_triangle_indices=arg_triangle_indices;
}

void CgTriCube::init( std::string filename)
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


const std::vector<glm::vec3>& CgTriCube::getVertices() const
{
  return m_vertices;
}

const std::vector<glm::vec3>& CgTriCube::getVertexNormals() const
{
  return m_vertex_normals;
}

const std::vector<glm::vec3>& CgTriCube::getVertexColors() const
{
  return m_vertex_colors;
}

const std::vector<glm::vec2>& CgTriCube:: getVertexTexCoords() const
{
  return m_tex_coords;
}

const std::vector<unsigned int>& CgTriCube::getTriangleIndices() const
{
  return m_triangle_indices;
}

const std::vector<glm::vec3>& CgTriCube::getFaceNormals() const
{
  return m_face_normals;
}

const std::vector<glm::vec3>& CgTriCube::getTriangleGravities() const
{
  return m_triangle_gravities;
}

const std::vector<glm::vec3>& CgTriCube::getFaceColors() const
{
  return m_face_colors;
}
