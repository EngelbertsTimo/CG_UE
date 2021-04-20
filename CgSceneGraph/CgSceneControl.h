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

class CgSceneControl : public CgObserver, public CgBaseSceneControl
{
public:
  CgSceneControl();
  ~CgSceneControl();
  void handleEvent(CgBaseEvent* e);
  void setRenderer(CgBaseRenderer* r);

  void renderObjects();

private:

  // A3 Hilfsmethoden
  void a3_object_initiation();
  void a3_Renderer_render();
  void a3_Renderer_init();
  void a3_Renderer_reset();


  // A4 Hilfsmethoden
  void a4_object_initiation();
  void a4_Renderer_render();
  void a4_Renderer_init();
  void a4_Renderer_reset();
  void a4_LRA_mitteln(int schritte, int iterationen);

  // A5 Hilfsmethoden
  void a5_object_initiation();
  void a5_Renderer_render();
  void a5_Renderer_init();
  void a5_Renderer_reset();

  // A6 Hilfsmethoden
  void a6_object_initiation();
  void a6_Renderer_render();
  void a6_Renderer_init();
  void a6_Renderer_reset();

  // A7 Hilfsmethoden
  void a7_object_initiation();
  void a7_Renderer_render();
  void a7_Renderer_init();
  void a7_Renderer_reset();

  // A8 Hilfsmethoden
  void a8_object_initiation();
  void a8_Renderer_render();
  void a8_Renderer_init();
  void a8_Renderer_reset();



  int mode;

  CgBaseRenderer* m_renderer;

  // A3 Objekte
  CgExampleTriangle* m_triangle;
  CgTriCube* m_tricube;
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
  CgPolyline* m_polyline12;

  // A4 Objekte
  CgPolyline* m_polyline;
  std::vector<glm::vec3> a4_workvector;

  // A5 Objekte

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
