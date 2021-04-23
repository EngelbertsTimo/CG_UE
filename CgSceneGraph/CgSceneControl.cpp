#include "CgSceneControl.h"
#include "CgBase/CgEnums.h"
#include "CgEvents/CgMouseEvent.h"
#include "CgEvents/CgKeyEvent.h"
#include "CgEvents/CgWindowResizeEvent.h"
#include "CgEvents/CgLoadObjFileEvent.h"
#include "CgEvents/CgTrackballEvent.h"
#include "CgEvents/CgColorChangeEvent.h"
#include "CgEvents/CgButtonEvent.h"
#include "CgEvents/CgAufgabenStatusEvent.h"
#include "CgEvents/CgResetEvent.h"
#include "CgEvents/CgLRAglaetenEvent.h"
#include "CgEvents/CgRotationEvent.h"
#include "CgEvents/CgShowNormalsEvent.h"
#include "CgBase/CgBaseRenderer.h"
#include "CgExampleTriangle.h"
#include "cgtricube.h"
#include "CgPolyline.h"
#include "CgRotationBody.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "CgUtils/ObjLoader.h"
#include <string>
#include <cmath>

CgSceneControl::CgSceneControl()
{

  global_id =0;

  m_triangle=nullptr;
  a3_tricube=nullptr;
  a4_polyline=nullptr;
  a4_rotationBody = nullptr;
  // ?
  m_current_transformation=glm::mat4(1.);

  // Blickwinkel
  m_lookAt_matrix= glm::lookAt(glm::vec3(0.0,0.0,4.0),glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,1.0,0.0));


  // Projekt Einstellungen
  m_proj_matrix= glm::mat4x4(glm::vec4(1.792591, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.792591, 0.0, 0.0), glm::vec4(0.0, 0.0, -1.0002, -1.0), glm::vec4(0.0, 0.0, -0.020002, 0.0));

  // Scroll Einstellunge
  m_trackball_rotation=glm::mat4(1.);

  // Inintialisierung
  mode = 2;

  // Aufgaben Fraben vorbestimmen
  m_initial_color_a3 = m_color_a3 = glm::vec4(1.0,0.0,0.0,1.0);
  m_initial_color_a4 = m_color_a4 = glm::vec4(0.0,1.0,0.0,1.0);
  m_initial_color_a5 =  m_color_a5 = glm::vec4(0.0,0.0,1.0,1.0);
  m_initial_color_a6 = m_color_a6 = glm::vec4(1.0,0.0,1.0,1.0);
  m_initial_color_a7 = m_color_a7 = glm::vec4(0.0,1.0,1.0,1.0);
  m_initial_color_a8 = m_color_a8 = glm::vec4(0.5,0.5,1.0,1.0);



  m_triangle= new CgExampleTriangle(21);

  //Aufgaben status initierieren
  a3_active = false;
  a4_active = false;
  a5_active = false;
  a6_active = false;
  a7_active = false;
  a8_active = false;

  //Aufgaben nomralen status initierieren
  a3_Face_normal_Vectors = false;
  a4_Face_normal_Vectors = false;
  a5_Face_normal_Vectors = false;
  a6_Face_normal_Vectors = false;
  a7_Face_normal_Vectors = false;
  a8_Face_normal_Vectors = false;

  a3_Vertex_normal_Vectors = false;
  a4_Vertex_normal_Vectors = false;
  a5_Vertex_normal_Vectors = false;
  a6_Vertex_normal_Vectors = false;
  a7_Vertex_normal_Vectors = false;
  a8_Vertex_normal_Vectors = false;

  //Objecte Erstellen
  a3_object_initiation();
  a4_object_initiation();
  a5_object_initiation();
  a6_object_initiation();
  a7_object_initiation();
  a8_object_initiation();


}


CgSceneControl::~CgSceneControl()
{
  a3_delete();
  a4_delete();
  a5_delete();
  a6_delete();
  a7_delete();
  a8_delete();


}

int CgSceneControl::assign_id(){
  ++global_id;
  return global_id;
}

void CgSceneControl::setRenderer(CgBaseRenderer* r)
{
  m_renderer=r;
  m_renderer->setSceneControl(this);
  /*if (mode==1){
      if(m_triangle!=NULL)
        m_renderer->init(m_triangle);
    } else if(mode==2){
      a3_Renderer_init();
    }*/

  if(a3_active)
    a3_Renderer_init();
  if(a4_active)
    a4_Renderer_init();
  if(a5_active)
    a5_Renderer_init();
  if(a6_active)
    a6_Renderer_init();
  if(a7_active)
    a7_Renderer_init();
  if(a8_active)
    a8_Renderer_init();

}


void CgSceneControl::renderObjects()
{

  // Materialeigenschaften setzen
  // sollte ja eigentlich pro Objekt unterschiedlich sein können, naja bekommen sie schon hin....

  std::cout << "CgSCeneControl: " <<"; render"<<std::endl;

  m_renderer->setUniformValue("matDiffuseColor",glm::vec4(0.35,0.31,0.09,1.0));
  m_renderer->setUniformValue("lightDiffuseColor",glm::vec4(1.0,1.0,1.0,1.0));


  m_renderer->setUniformValue("matAmbientColor",glm::vec4(0.25,0.22,0.06,1.0));
  m_renderer->setUniformValue("lightAmbientColor",glm::vec4(1.0,1.0,1.0,1.0));


  m_renderer->setUniformValue("matSpecularColor",glm::vec4(0.8,0.72,0.21,1.0));
  m_renderer->setUniformValue("lightSpecularColor",glm::vec4(1.0,1.0,1.0,1.0));

  glm::mat4 mv_matrix = m_lookAt_matrix * m_trackball_rotation* m_current_transformation ;
  glm::mat3 normal_matrix = glm::transpose(glm::inverse(glm::mat3(mv_matrix)));


  m_renderer->setUniformValue("projMatrix",m_proj_matrix);
  m_renderer->setUniformValue("modelviewMatrix",mv_matrix);
  m_renderer->setUniformValue("normalMatrix",normal_matrix);

  if(a3_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a3);
      a3_Renderer_render();
    }
  if(a4_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a4);
      a4_Renderer_render();
    }
  if(a5_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a5);
      a5_Renderer_render();
    }
  if(a6_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a6);
      a6_Renderer_render();
    }
  if(a7_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a7);
      a7_Renderer_render();
    }
  if(a8_active)
    {
      m_renderer->setUniformValue("mycolor",m_color_a8);
      a8_Renderer_render();
    }
}



void CgSceneControl::handleEvent(CgBaseEvent* e)
{
  // die Enums sind so gebaut, dass man alle Arten von MausEvents über CgEvent::CgMouseEvent abprüfen kann,
  // siehe dazu die CgEvent enums im CgEnums.h


  if(e->getType() & Cg::AufagbenStatusEvent)
    {
      CgAufgabenStatusEvent* ev =(CgAufgabenStatusEvent*)e;
      bool aufgaben_status=ev->getAufgabenStatus();

      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Aufgabe "<<ev->getAufagbenNummer()<<" | Statusänderung zu "<<aufgaben_status <<std::endl;


      switch (ev->getAufagbenNummer()) {
        case 3:
          if(aufgaben_status){
              a3_active=true;
              a3_Renderer_init();
            }
          else
            a3_active=false;
          break;
        case 4:
          if(aufgaben_status){
              a4_active=true;
              a4_Renderer_init();
            }
          else
            a4_active=false;
          break;
        case 5:
          if(aufgaben_status){
              a5_active=true;
              a5_Renderer_init();
            }
          else
            a5_active=false;
          break;
        case 6:
          if(aufgaben_status){
              a6_active=true;
              a6_Renderer_init();
            }
          else
            a6_active=false;
          break;
        case 7:
          if(aufgaben_status){
              a7_active=true;
              a7_Renderer_init();
            }
          else
            a7_active=false;
          break;
        case 8:

          if(aufgaben_status){
              a8_active=true;
              a8_Renderer_init();
            }
          else
            a8_active=false;
          break;
        default:
          break;
        }
      m_renderer->redraw();
    }

  if(e->getType() & Cg::ShowNormalsEvent)
    {
      CgShowNormalsEvent* ev =(CgShowNormalsEvent*)e;
      bool normal_status;
      if(ev->getNormalStatus())
        normal_status=true;
      else
        normal_status=false;

      int normal_type=ev->getNormalType();

      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Aufgabe "<<ev->getAufagbenNummer()<<" | Normal Statusänderung zu "<<normal_status << "| NormalType = "<<normal_type <<" (1:Face ; 2:Vertex)" <<std::endl;

      switch (ev->getAufagbenNummer()) {
        case 3:
          switch (normal_type) {
            case 1:
              a3_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a3_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a3_Renderer_init();
          break;
        case 4:
          switch (normal_type) {
            case 1:
              a4_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a4_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a4_Renderer_init();
          break;
        case 5:
          switch (normal_type) {
            case 1:
              a5_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a5_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a5_Renderer_init();
          break;
        case 6:
          switch (normal_type) {
            case 1:
              a6_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a6_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a6_Renderer_init();
          break;
        case 7:
          switch (normal_type) {
            case 1:
              a7_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a7_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a7_Renderer_init();
          break;
        case 8:
          switch (normal_type) {
            case 1:
              a8_Face_normal_Vectors=normal_status;
              break;
            case 2:
              a8_Vertex_normal_Vectors=normal_status;
              break;
            default:
              break;
            }
          a8_Renderer_init();
          break;
        default:
          break;
        }
      m_renderer->redraw();
    }

  if(e->getType() & Cg::ResetEvent)
    {
      CgResetEvent* ev = (CgResetEvent*)e;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Reset Aufgabe "<< ev->getAufgabe()<<std::endl;

      switch (ev->getAufgabe()) {
        case 3:
          a3_Renderer_reset();
          break;
        case 4:
          a4_Renderer_reset();
          break;
        case 5:
          a5_Renderer_reset();
          break;
        case 6:
          a6_Renderer_reset();
          break;
        case 7:
          a7_Renderer_reset();
          break;
        case 8:
          a8_Renderer_reset();
          break;
        default:
          break;
        }

    }

  if(e->getType() & Cg::ColorChangeEvent)
    {
      CgColorChangeEvent* ev = (CgColorChangeEvent*)e;

      double redPart;
      if(ev->getRed()==0)
        redPart=0;
      else
        redPart=ev->getRed()/256.0;

      double greenPart;
      if(ev->getGreen()==0)
        greenPart=0;
      else
        greenPart=ev->getGreen()/256.0;

      double bluePart;
      if(ev->getBlue()==0)
        bluePart=0;
      else
        bluePart=ev->getBlue()/256.0;

      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Color Change Aufgabe "<< ev->getAufgabe()<<"; Modifier: red: " << ev->getRed() <<"; green: " << ev->getGreen()<<"; blue: " << ev->getBlue() <<std::endl;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Color Change Aufgabe "<< ev->getAufgabe()<<"; Ergebnis: red: " << redPart <<"; green: " << greenPart<<"; blue: " << bluePart <<std::endl;

      switch (ev->getAufgabe()) {
        case 3:
          m_color_a3 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        case 4:
          m_color_a4 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        case 5:
          m_color_a5 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        case 6:
          m_color_a6 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        case 7:
          m_color_a7 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        case 8:
          m_color_a8 = glm::vec4(redPart,greenPart,bluePart,1.0);
          break;
        default:
          break;
        }
      // m_color_a3 = glm::vec4(redPart,greenPart,bluePart,1.0);


      m_renderer->redraw();
    }

  if(e->getType() & Cg::LRAglaetenEvent)
    {
      CgLRAglaetenEvent* ev =(CgLRAglaetenEvent*)e;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; LRA Glätten: Aufgabe "<< ev->getAufgabe()<<" | Mittungsschritte: "<<ev->getSchritte()<<"; Iterationen: "<<ev->getIterationen()  <<std::endl;

      switch (ev->getAufgabe()) {
        case 4:
          a4_LRA_mitteln(ev->getSchritte(),ev->getIterationen());
          break;
        default:
          break;
        }
    }

  if(e->getType() & Cg::RotationEvent)
    {
      CgRotationEvent* ev =(CgRotationEvent*)e;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Roteieren: Aufgabe "<< ev->getAufgabe()<<"| Rotations Typ: "<<ev->getRotationType() <<" | Rotations Segmente: "<<ev->getSegmente() <<std::endl;
      switch (ev->getAufgabe()) {
        case 4:
          a4_roteieren(ev->getSegmente(),ev->getRotationType());
          break;
        default:
          break;
        }
    }

  if(e->getType() & Cg::ButtonEvent)
    {
      CgButtonEvent* ev =(CgButtonEvent*)e;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; mode chaneged"  <<std::endl;
      if (mode==1)
        mode =2;
      else
        mode=1;

      a3_Renderer_init();
      m_renderer->redraw();
    }




  if(e->getType() & Cg::CgMouseEvent)
    {
      CgMouseEvent* ev = (CgMouseEvent*)e;
      std::cout << "CgSCeneControl: " << *ev << "Mouse Event"<< std::endl;

      // hier kommt jetzt die Abarbeitung des Events hin...
    }


  if(e->getType() & Cg::CgTrackballEvent)
    {
      CgTrackballEvent* ev = (CgTrackballEvent*)e;


      m_trackball_rotation=ev->getRotationMatrix();
      m_renderer->redraw();

    }


  // die Enums sind so gebaut, dass man alle Arten von KeyEvents über CgEvent::CgKeyEvent abprüfen kann,
  // siehe dazu die CgEvent enums im CgEnums.h
  // momentan werden nur KeyPressEvents gefangen.

  if(e->getType() & Cg::CgKeyEvent)
    {
      CgKeyEvent* ev = (CgKeyEvent*)e;
      std::cout << "CgSCeneControl: " << *ev <<std::endl;

      if(ev->text()=="+")
        {
          glm::mat4 scalemat = glm::mat4(1.);
          scalemat = glm::scale(scalemat,glm::vec3(1.2,1.2,1.2));
          m_current_transformation=m_current_transformation*scalemat;
          m_renderer->redraw();
        }
      if(ev->text()=="-")
        {
          glm::mat4 scalemat = glm::mat4(1.);
          scalemat = glm::scale(scalemat,glm::vec3(0.8,0.8,0.8));

          m_current_transformation=m_current_transformation*scalemat;

          m_renderer->redraw();
        }
      // hier kommt jetzt die Abarbeitung des Events hin...
    }

  if(e->getType() & Cg::WindowResizeEvent)
    {
      CgWindowResizeEvent* ev = (CgWindowResizeEvent*)e;
      std::cout << "CgSCeneControl: " << *ev <<std::endl;
      m_proj_matrix=glm::perspective(45.0f, (float)(ev->w()) / ev->h(), 0.01f, 100.0f);
    }

  if(e->getType() & Cg::LoadObjFileEvent)
    {

      CgLoadObjFileEvent* ev = (CgLoadObjFileEvent*)e;


      ObjLoader* loader= new ObjLoader();
      loader->load(ev->FileName());

      std::cout << "CgSCeneControl: " << ev->FileName() << std::endl;

      std::vector<glm::vec3> pos;
      loader->getPositionData(pos);

      std::vector<glm::vec3> norm;
      loader->getNormalData(norm);

      std::vector<unsigned int> indx;
      loader->getFaceIndexData(indx);


      if(mode==1){
          m_triangle->init(pos,norm,indx);
          m_renderer->init(m_triangle);
        } else if(mode==2){
          a3_tricube->init(pos,norm,indx);
          m_renderer->init(a3_tricube);
        }
      m_renderer->redraw();
    }

  // an der Stelle an der ein Event abgearbeitet ist wird es auch gelöscht.
  delete e;


}

// A3 Hilfsmethoden id:3000-3999
void CgSceneControl::a3_object_initiation()
{
  a3_tricube = new CgTriCube(assign_id());
  a3_triCube_Face_Nomral_polylines=m_FaceNormales(a3_tricube);
  a3_triCube_Vertex_Nomral_polylines=m_VertexNormales(a3_tricube);

}

void CgSceneControl::a3_Renderer_render()
{
  if(a3_tricube!=NULL)
    m_renderer->render(a3_tricube);
  if(a3_Face_normal_Vectors){
      for (int i = 0; i < a3_triCube_Face_Nomral_polylines.size(); ++i) {
          m_renderer->render(a3_triCube_Face_Nomral_polylines[i]);
        }
    }
  if(a3_Vertex_normal_Vectors){
      for (int i = 0; i < a3_triCube_Vertex_Nomral_polylines.size(); ++i) {
          m_renderer->render(a3_triCube_Vertex_Nomral_polylines[i]);
        }
    }
}

void CgSceneControl::a3_Renderer_init()
{
  if(a3_tricube!=NULL)
    m_renderer->init(a3_tricube);

  if(a3_Face_normal_Vectors){
      for (int i = 0; i < a3_triCube_Face_Nomral_polylines.size(); ++i) {
          m_renderer->init(a3_triCube_Face_Nomral_polylines[i]);
        }
    }
  if(a3_Vertex_normal_Vectors){
      for (int i = 0; i < a3_triCube_Vertex_Nomral_polylines.size(); ++i) {
          m_renderer->init(a3_triCube_Vertex_Nomral_polylines[i]);
        }
    }
}

void CgSceneControl::a3_Renderer_reset()
{
  m_color_a3=m_initial_color_a3;
  a3_object_initiation();
  a3_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a3_delete(){

  if(a3_tricube!=NULL)
    delete a3_tricube;


}

// A4 Hilfsmethoden id:4000-4999
void CgSceneControl::a4_object_initiation()
{/*
  a4_workvector.clear();
  a4_workvector.push_back(glm::vec3(-0.0,-0.5,-0.5));
  a4_workvector.push_back(glm::vec3(0.0,0.0,0.0));
  a4_workvector.push_back(glm::vec3(0.5,0.5,0.5));

  a4_workvector.push_back(glm::vec3(-1.0,-1.0,-0.5));
  a4_workvector.push_back(glm::vec3(0.5,-0.5,-0.25));
  a4_workvector.push_back(glm::vec3(0.5,0.5,0.0));
  a4_workvector.push_back(glm::vec3(-1.0,1.0,0.25));
  a4_workvector.push_back(glm::vec3(-0.5,1.0,0.5));

*/

/*
  a4_workvector.push_back(glm::vec3(0.5,0.0,-0.5));
  a4_workvector.push_back(glm::vec3(0.75,0.0,-0.25));
  a4_workvector.push_back(glm::vec3(0.75,0.0,0.0));
  a4_workvector.push_back(glm::vec3(0.5,0.0,0.25));

*/

  a4_workvector.push_back(glm::vec3(0.5,0.0,-0.5));
  a4_workvector.push_back(glm::vec3(0.5,0.0,-0.25));
  a4_workvector.push_back(glm::vec3(0.5,0.0,0.0));
  a4_workvector.push_back(glm::vec3(0.5,0.0,0.25));


  /*
  a4_workvector.push_back(glm::vec3(1.0,0.0,-0.5));
  a4_workvector.push_back(glm::vec3(0.5,0.0,-0.25));
  a4_workvector.push_back(glm::vec3(0.5,0.0,0.0));
  a4_workvector.push_back(glm::vec3(1.0,0.0,0.25));
  a4_workvector.push_back(glm::vec3(0.5,0.0,0.5));
*/

  /* a4_workvector.push_back(glm::vec3(-1.0,0.0,-0.5));
  a4_workvector.push_back(glm::vec3(-1.0,0.0,-0.25));
  a4_workvector.push_back(glm::vec3(-1.0,00,0.0));
  a4_workvector.push_back(glm::vec3(-1.0,0.0,0.25));
  a4_workvector.push_back(glm::vec3(-1.0,0.0,0.5));
*/

  a4_polyline = new CgPolyline(assign_id(),a4_workvector);

  a4_rotation_Face_Nomral_polylines.clear();
  a4_rotation_Vertex_Nomral_polylines.clear();
  a4_rotationBody = nullptr;

}

void CgSceneControl::a4_Renderer_render()
{
  if(a4_polyline!=NULL)
    m_renderer->render(a4_polyline);

  if(a4_rotationBody!=NULL)
    m_renderer->render(a4_rotationBody);
  if(a4_Face_normal_Vectors){
      for (int i = 0; i < a4_rotation_Face_Nomral_polylines.size(); ++i) {
          m_renderer->render(a4_rotation_Face_Nomral_polylines[i]);
        }
    }
  if(a4_Vertex_normal_Vectors){
      for (int i = 0; i < a4_rotation_Vertex_Nomral_polylines.size(); ++i) {
          m_renderer->render(a4_rotation_Vertex_Nomral_polylines[i]);
        }
    }
}

void CgSceneControl::a4_Renderer_init()
{
  if(a4_polyline!=NULL)
    m_renderer->init(a4_polyline);
  if(a4_rotationBody!=NULL)
    m_renderer->init(a4_rotationBody);
  if(a4_Face_normal_Vectors){
      for (int i = 0; i < a4_rotation_Face_Nomral_polylines.size(); ++i) {
          m_renderer->init(a4_rotation_Face_Nomral_polylines[i]);
        }
    }
  if(a4_Vertex_normal_Vectors){
      for (int i = 0; i < a4_rotation_Vertex_Nomral_polylines.size(); ++i) {
          m_renderer->init(a4_rotation_Vertex_Nomral_polylines[i]);
        }
    }
}

void CgSceneControl::a4_Renderer_reset()
{  

  m_color_a4=m_initial_color_a4;
  a4_object_initiation();
  a4_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a4_delete(){
  if(a4_rotationBody!=NULL)
    delete a4_rotationBody;
  if(a4_polyline!=NULL)
    delete a4_polyline;

  for (int i = 0; i < a4_rotation_Face_Nomral_polylines.size(); ++i) {
      if(a4_rotation_Face_Nomral_polylines[i]!=NULL)
        delete a4_rotation_Face_Nomral_polylines[i];
    }
  for (int i = 0; i < a4_rotation_Vertex_Nomral_polylines.size(); ++i) {
      if(a4_rotation_Vertex_Nomral_polylines[i]!=NULL)
        delete a4_rotation_Vertex_Nomral_polylines[i];
    }
}

void CgSceneControl::a4_LRA_mitteln(int schritte, int iterationen){ 
  a4_workvector = m_LRA_mitteln(schritte,iterationen,a4_workvector);
  std::cout << "CgSCeneControl: hier" <<std::endl;
  a4_polyline = new CgPolyline(assign_id(),a4_workvector);

  a4_Renderer_init();
  a4_Renderer_render();
  m_renderer->redraw();
}




void CgSceneControl::a4_roteieren(int segmente, int rotationType)
{
  switch (rotationType) {
    case 1:
      a4_rotationBody= m_roteieren_1(segmente,a4_workvector);//new CgRotationBody(assign_id(),segmente,a4_workvector.size(),a4_rotationvector);
      break;
    case 2:
      a4_rotationBody= m_roteieren_2(segmente,a4_workvector);//new CgRotationBody(assign_id(),segmente,a4_workvector.size(),a4_rotationvector);
      break;
    case 3:
      a4_rotationBody= m_roteieren_3(segmente,a4_workvector);//new CgRotationBody(assign_id(),segmente,a4_workvector.size(),a4_rotationvector);
      break;
    default:
      break;
    }
  //a4_rotationBody= m_roteieren_3(segmente,a4_workvector);//new CgRotationBody(assign_id(),segmente,a4_workvector.size(),a4_rotationvector);

  a4_rotation_Face_Nomral_polylines = m_FaceNormales(a4_rotationBody);

  a4_rotation_Vertex_Nomral_polylines = m_VertexNormales(a4_rotationBody);

  a4_Renderer_init();
  a4_Renderer_render();
  m_renderer->redraw();
}


// A5 Hilfsmethoden id:5000-5999
void CgSceneControl::a5_object_initiation()
{
}

void CgSceneControl::a5_Renderer_render()
{

}

void CgSceneControl::a5_Renderer_init()
{

}

void CgSceneControl::a5_Renderer_reset()
{
  m_color_a5=m_initial_color_a5;
  a5_object_initiation();
  a5_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a5_delete(){


}

// A6 Hilfsmethoden id:6000-6999
void CgSceneControl::a6_object_initiation()
{

}

void CgSceneControl::a6_Renderer_render()
{
  if(a6_Face_normal_Vectors){

    }
  if(a6_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a6_Renderer_init()
{
  if(a6_Face_normal_Vectors){

    }
  if(a6_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a6_Renderer_reset()
{
  m_color_a6=m_initial_color_a6;
  a6_object_initiation();
  a6_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a6_delete(){


}

// A7 Hilfsmethoden id:7000-7999
void CgSceneControl::a7_object_initiation()
{

}

void CgSceneControl::a7_Renderer_render()
{
  if(a7_Face_normal_Vectors){

    }
  if(a7_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a7_Renderer_init()
{
  if(a7_Face_normal_Vectors){

    }
  if(a7_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a7_Renderer_reset()
{
  m_color_a7=m_initial_color_a7;
  a7_object_initiation();
  a7_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a7_delete(){


}

// A8 Hilfsmethoden id:8000-8999
void CgSceneControl::a8_object_initiation()
{

}

void CgSceneControl::a8_Renderer_render()
{
  if(a8_Face_normal_Vectors){

    }
  if(a8_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a8_Renderer_init()
{
  if(a8_Face_normal_Vectors){

    }
  if(a8_Vertex_normal_Vectors){

    }
}

void CgSceneControl::a8_Renderer_reset()
{
  m_color_a8=m_initial_color_a8;
  a8_object_initiation();
  a8_Renderer_init();
  m_renderer->redraw();
}

void CgSceneControl::a8_delete(){


}

//Arbeitsmethoden


std::vector<glm::vec3> CgSceneControl::m_LRA_mitteln(int schritte, int iterationen,std::vector<glm::vec3> lra_workVector_input){
  std::vector<glm::vec3> lra_workVector=lra_workVector_input;

  if(schritte<(lra_workVector.size()*2)){
      int initial_length;
      double x1,x2,y1,y2,z1,z2;
      for (int j = 0; j < iterationen; ++j) {
          std::cout << "CgSCeneControl: glätten: iteration: "<<j+1 <<std::endl;
          initial_length=lra_workVector.size();
          for (int x = 0; x < initial_length; ++x) {
              std::cout << "CgSCeneControl: glätten: vorbereiten: "<<x+1 <<std::endl;
              lra_workVector.insert(lra_workVector.begin()+(x*2)+1,lra_workVector[x*2]);
            }

          for (int y = 0; y < schritte; ++y) {
              std::cout << "CgSCeneControl: glätten: schritt: "<<y+1 <<std::endl;
              for (int i = 0; i < lra_workVector.size()-1; ++i) {
                  std::cout << "CgSCeneControl: glätten: durchlauf: "<<i+1 <<std::endl;
                  x1=lra_workVector[i][0];
                  x2=lra_workVector[i+1][0];

                  y1=lra_workVector[i][1];
                  y2=lra_workVector[i+1][1];

                  z1=lra_workVector[i][2];
                  z2=lra_workVector[i+1][2];
                  lra_workVector[i]=glm::vec3((x1+x2)/2,(y1+y2)/2,(z1+z2)/2);
                }
              lra_workVector.erase(lra_workVector.begin()+lra_workVector.size()-1);
            }
          std::cout << "CgSCeneControl: glätten: Gesamtzahl Unterpunkte: "<<lra_workVector.size() <<std::endl;
        }

    } else {
      std::cout << "CgSCeneControl: LRA glätten: schritte: zu viele Mittelschritte("<<schritte<<")  angegeben; Maximale Mittlungschrittanzahl = "<<(lra_workVector.size()*2)-1 <<std::endl;
    }
  return lra_workVector;
}

CgRotationBody* CgSceneControl::m_roteieren_1(int segmente,std::vector<glm::vec3> r1_workVector){
  std::vector<glm::vec3> r1_zws_old_vector=r1_workVector;
  std::vector<glm::vec3> r1_zws_new_vector,r1_rotationVector;

  double winkel=2* M_PI/segmente;

  for (int j = 0; j < r1_workVector.size(); ++j) {
      r1_rotationVector.push_back(glm::vec3((r1_zws_old_vector[j][0]),(r1_zws_old_vector[j][1]),r1_zws_old_vector[j][2]));
    }

  for (int i = 1; i < segmente; ++i) {
      for (int j = 0; j < r1_workVector.size(); ++j) {
          double v1 =(r1_zws_old_vector[j][0]*cos(winkel)-r1_zws_old_vector[j][1]*sin(winkel));
          double v2 =(r1_zws_old_vector[j][0]*sin(winkel)+r1_zws_old_vector[j][1]*cos(winkel));
          r1_zws_new_vector.push_back(glm::vec3(v1,v2,r1_zws_old_vector[j][2]));
          r1_rotationVector.push_back(glm::vec3(v1,v2,r1_zws_old_vector[j][2]));
        }
      r1_zws_old_vector.clear();
      r1_zws_old_vector=r1_zws_new_vector;
      r1_zws_new_vector.clear();
    }
  CgRotationBody*  rotationBody= new CgRotationBody(assign_id(),segmente,a4_workvector.size(),r1_rotationVector);

  return rotationBody;
}

CgRotationBody* CgSceneControl::m_roteieren_2(int segmente,std::vector<glm::vec3> r2_workVector){

  std::vector<glm::vec3> r2_zws_old_vector=r2_workVector;
  std::vector<glm::vec3> r2_zws_new_vector,r2_rotationVector;

  double winkel=2* M_PI/segmente;

  for (int j = 0; j < r2_workVector.size(); ++j) {
      r2_rotationVector.push_back(glm::vec3((r2_zws_old_vector[j][0]),(r2_zws_old_vector[j][1]),r2_zws_old_vector[j][2]));
    }

  for (int i = 1; i < segmente; ++i) {
      for (int j = 0; j < r2_workVector.size(); ++j) {
          double v1 =(r2_zws_old_vector[j][0]*cos(winkel)-r2_zws_old_vector[j][2]*sin(winkel));
          double v3 =(r2_zws_old_vector[j][0]*sin(winkel)+r2_zws_old_vector[j][2]*cos(winkel));
          r2_zws_new_vector.push_back(glm::vec3(v1,r2_zws_old_vector[j][1],v3));
          r2_rotationVector.push_back(glm::vec3(v1,r2_zws_old_vector[j][1],v3));
        }
      r2_zws_old_vector.clear();
      r2_zws_old_vector=r2_zws_new_vector;
      r2_zws_new_vector.clear();
    }
  CgRotationBody*  rotationBody= new CgRotationBody(assign_id(),segmente,a4_workvector.size(),r2_rotationVector);

  return rotationBody;
}

CgRotationBody* CgSceneControl::m_roteieren_3(int segmente,std::vector<glm::vec3> r3_workVector){

  std::vector<glm::vec3> r3_zws_old_vector=r3_workVector;
  std::vector<glm::vec3> r3_zws_new_vector,r3_rotationVector;

  double winkel=2* M_PI/segmente;

  for (int j = 0; j < r3_workVector.size(); ++j) {
      r3_rotationVector.push_back(glm::vec3((r3_zws_old_vector[j][0]),(r3_zws_old_vector[j][1]),r3_zws_old_vector[j][2]));
    }

  for (int i = 1; i < segmente; ++i) {
      for (int j = 0; j < r3_workVector.size(); ++j) {
          double v2 =(r3_zws_old_vector[j][1]*cos(winkel)-r3_zws_old_vector[j][2]*sin(winkel));
          double v3 =(r3_zws_old_vector[j][1]*sin(winkel)+r3_zws_old_vector[j][2]*cos(winkel));
          r3_zws_new_vector.push_back(glm::vec3(r3_zws_old_vector[j][0],v2,v3));
          r3_rotationVector.push_back(glm::vec3(r3_zws_old_vector[j][0],v2,v3));
        }
      r3_zws_old_vector.clear();
      r3_zws_old_vector=r3_zws_new_vector;
      r3_zws_new_vector.clear();
    }
  CgRotationBody*  rotationBody= new CgRotationBody(assign_id(),segmente,a4_workvector.size(),r3_rotationVector);

  return rotationBody;
}


std::vector<CgPolyline*> CgSceneControl::m_FaceNormales(CgBaseTriangleMesh* workBody){
  std::vector<CgPolyline*> result;

  double x1,x2,x3,y1,y2,y3,z1,z2,z3=0;
  for (int i = 0; i < workBody->getTriangleIndices().size(); i=i+3) {

      x1=workBody->getVertices()[workBody->getTriangleIndices()[i]][0];

      y1=workBody->getVertices()[workBody->getTriangleIndices()[i]][1];
      z1=workBody->getVertices()[workBody->getTriangleIndices()[i]][2];

      x2=workBody->getVertices()[workBody->getTriangleIndices()[i+1]][0];
      y2=workBody->getVertices()[workBody->getTriangleIndices()[i+1]][1];
      z2=workBody->getVertices()[workBody->getTriangleIndices()[i+1]][2];

      x3=workBody->getVertices()[workBody->getTriangleIndices()[i+2]][0];
      y3=workBody->getVertices()[workBody->getTriangleIndices()[i+2]][1];
      z3=workBody->getVertices()[workBody->getTriangleIndices()[i+2]][2];

      result.push_back(new CgPolyline(assign_id(),glm::vec3(((x1+x2+x3)/3),((y1+y2+y3)/3),((z1+z2+z3)/3)),workBody->getFaceNormals()[i/3]));
    }
  return result;
}

std::vector<CgPolyline*> CgSceneControl::m_VertexNormales(CgBaseTriangleMesh* workBody){
  std::vector<CgPolyline*> result;
  for (int j = 0; j < workBody->getVertices().size(); ++j) {
      result.push_back(new CgPolyline(assign_id(),workBody->getVertices()[j],workBody->getVertexNormals()[j]));
    }
  return result;
}
