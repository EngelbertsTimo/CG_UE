#ifndef CGSCENECONTROL_H
#define CGSCENECONTROL_H

#include "CgBase/CgObserver.h"
#include "CgBase/CgBaseSceneControl.h"
#include <glm/glm.hpp>
#include <vector>

class CgBaseEvent;
class CgBaseRenderer;
class CgExampleTriangle;
class CgTriCube;
class CgPolyline;
class CgRotationBody;
class CgBaseTriangleMesh;

class CgSceneControl : public CgObserver, public CgBaseSceneControl
{
public:
  CgSceneControl();
  ~CgSceneControl();
  void handleEvent(CgBaseEvent* e);
  void setRenderer(CgBaseRenderer* r);

  void renderObjects();

private:

  int assign_id();


  // A3 Hilfsmethoden
  void a3_object_initiation();
  void a3_Renderer_render();
  void a3_Renderer_init();
  void a3_Renderer_reset();
  void a3_delete();


  // A4 Hilfsmethoden
  void a4_object_initiation();
  void a4_Renderer_render();
  void a4_Renderer_init();
  void a4_Renderer_reset();
  void a4_delete();
  void a4_LRA_mitteln(int schritte, int iterationen);
  void a4_roteieren(int segmente);

  // A5 Hilfsmethoden
  void a5_object_initiation();
  void a5_Renderer_render();
  void a5_Renderer_init();
  void a5_Renderer_reset();
  void a5_delete();

  // A6 Hilfsmethoden
  void a6_object_initiation();
  void a6_Renderer_render();
  void a6_Renderer_init();
  void a6_Renderer_reset();
  void a6_delete();

  // A7 Hilfsmethoden
  void a7_object_initiation();
  void a7_Renderer_render();
  void a7_Renderer_init();
  void a7_Renderer_reset();
  void a7_delete();

  // A8 Hilfsmethoden
  void a8_object_initiation();
  void a8_Renderer_render();
  void a8_Renderer_init();
  void a8_Renderer_reset();
  void a8_delete();

  // Arbeits methoden
  std::vector<glm::vec3> m_LRA_mitteln(int schritte, int iterationen);

  CgRotationBody* m_roteieren_1(int segmente);
  CgRotationBody* m_roteieren_2(int segmente);
  CgRotationBody* m_roteieren_3(int segmente);
  std::vector<CgPolyline*> m_FaceNormales(CgBaseTriangleMesh* workBody);
  std::vector<CgPolyline*> m_VertexNormales(CgBaseTriangleMesh* workBody);

  int global_id;

  int mode;

  CgBaseRenderer* m_renderer;

  // A3 Objekte
  CgExampleTriangle* m_triangle;
  CgTriCube* a3_tricube;
  std::vector<CgPolyline*> a3_triCube_Face_Nomral_polylines;
  std::vector<CgPolyline*> a3_triCube_Vertex_Nomral_polylines;
  /*
  CgPolyline* m_polyline1;
  CgPolyline* m_polyline2;
  CgPolyline* m_polyline3;
  CgPolyline* m_polyline4;
  CgPolyline* m_polyline5;
  CgPolyline* m_polyline6;
  CgPolyline* m_polyline7;
  CgPolyline* m_polyline8;
  CgPolyline* m_polyline9;
  CgPolyline* m_polyline10;
  CgPolyline* m_polyline11;
  CgPolyline* m_polyline12;*/

  // A4 Objekte
  CgPolyline* a4_polyline;
  std::vector<glm::vec3> a4_workvector;
  std::vector<glm::vec3> a4_rotationvector;
  CgRotationBody* a4_rotationBody;
  std::vector<CgPolyline*> a4_rotation_Face_Nomral_polylines;
  std::vector<CgPolyline*> a4_rotation_Vertex_Nomral_polylines;
  // A5 Objekte

  CgPolyline* m_A5_1_polyline;
  CgPolyline* m_A5_2_polyline;
  CgPolyline* m_A5_3_polyline;
  CgPolyline* m_A5_4_polyline;
  CgPolyline* m_A5_5_polyline;
  CgPolyline* m_A5_6_polyline;
  std::vector<glm::vec3> a5_workvector;
  std::vector<glm::vec3> a5_rotationvector;
  CgRotationBody* a5_rotationBody;
  std::vector<CgPolyline*> a5_rotationNomral_polylines;

  // A6 Objekte

  // A7 Objekte

  // A8 Objekte


  // Globale Objekte
  bool a3_active;
  bool a4_active;
  bool a5_active;
  bool a6_active;
  bool a7_active;
  bool a8_active;

  bool a3_Face_normal_Vectors;
  bool a4_Face_normal_Vectors;
  bool a5_Face_normal_Vectors;
  bool a6_Face_normal_Vectors;
  bool a7_Face_normal_Vectors;
  bool a8_Face_normal_Vectors;

  bool a3_Vertex_normal_Vectors;
  bool a4_Vertex_normal_Vectors;
  bool a5_Vertex_normal_Vectors;
  bool a6_Vertex_normal_Vectors;
  bool a7_Vertex_normal_Vectors;
  bool a8_Vertex_normal_Vectors;

  glm::mat4 m_current_transformation;
  glm::mat4 m_trackball_rotation;
  glm::mat4 m_lookAt_matrix;
  glm::mat4 m_proj_matrix;

  glm::vec4 m_color_a3;
  glm::vec4 m_color_a4;
  glm::vec4 m_color_a5;
  glm::vec4 m_color_a6;
  glm::vec4 m_color_a7;
  glm::vec4 m_color_a8;

  glm::vec4 m_initial_color_a3;
  glm::vec4 m_initial_color_a4;
  glm::vec4 m_initial_color_a5;
  glm::vec4 m_initial_color_a6;
  glm::vec4 m_initial_color_a7;
  glm::vec4 m_initial_color_a8;
  std::vector<CgPolyline*> m_render_lines;

};

#endif // CGSCENECONTROL_H
