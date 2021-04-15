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

  int mode;

  CgBaseRenderer* m_renderer;

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

  glm::mat4 m_current_transformation;
  glm::mat4 m_trackball_rotation;
  glm::mat4 m_lookAt_matrix;
  glm::mat4 m_proj_matrix;
  glm::vec4 m_color;
  std::vector<CgPolyline*> m_render_lines;

};

#endif // CGSCENECONTROL_H
