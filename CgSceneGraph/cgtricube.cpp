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
    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(2);
    m_triangle_indices.push_back(1);

    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(2);
    m_triangle_indices.push_back(3);

    //S1
    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(5);
    m_triangle_indices.push_back(4);

    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(5);

    //S2
    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(4);
    m_triangle_indices.push_back(2);

    m_triangle_indices.push_back(2);
    m_triangle_indices.push_back(4);
    m_triangle_indices.push_back(6);

    //S3
    m_triangle_indices.push_back(2);
    m_triangle_indices.push_back(6);
    m_triangle_indices.push_back(3);

    m_triangle_indices.push_back(3);
    m_triangle_indices.push_back(6);
    m_triangle_indices.push_back(7);

    //S4
    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(3);
    m_triangle_indices.push_back(5);

    m_triangle_indices.push_back(3);
    m_triangle_indices.push_back(7);
    m_triangle_indices.push_back(5);

    //Decke
    m_triangle_indices.push_back(4);
    m_triangle_indices.push_back(5);
    m_triangle_indices.push_back(6);

    m_triangle_indices.push_back(6);
    m_triangle_indices.push_back(5);
    m_triangle_indices.push_back(7);

    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));

    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
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

const std::vector<glm::vec3>& CgTriCube::getFaceColors() const
{
    return m_face_colors;
}
