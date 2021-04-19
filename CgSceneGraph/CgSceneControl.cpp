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
#include "CgBase/CgBaseRenderer.h"
#include "CgExampleTriangle.h"
#include "cgtricube.h"
#include "CgPolyline.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "CgUtils/ObjLoader.h"
#include <string>

CgSceneControl::CgSceneControl()
{
  m_triangle=nullptr;
  m_tricube=nullptr;

  // ?
  m_current_transformation=glm::mat4(1.);

  // Blickwinkel
  m_lookAt_matrix= glm::lookAt(glm::vec3(0.0,0.0,2.0),glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,1.0,0.0));

  // Projekt Einstellungen
  m_proj_matrix= glm::mat4x4(glm::vec4(1.792591, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.792591, 0.0, 0.0), glm::vec4(0.0, 0.0, -1.0002, -1.0), glm::vec4(0.0, 0.0, -0.020002, 0.0));

  // Scroll Einstellunge
  m_trackball_rotation=glm::mat4(1.);

  // Inintialisierung
  mode = 2;

  // Aufgaben Fraben vorbestimmen
  m_color_a3 = glm::vec4(1.0,0.0,0.0,1.0);
  m_color_a4 = glm::vec4(0.0,1.0,0.0,1.0);
  m_color_a5 = glm::vec4(0.0,0.0,1.0,1.0);
  m_color_a6 = glm::vec4(1.0,0.0,1.0,1.0);
  m_color_a7 = glm::vec4(0.0,1.0,1.0,1.0);
  m_color_a8 = glm::vec4(0.5,0.5,1.0,1.0);



  m_triangle= new CgExampleTriangle(21);

  //Aufgaben status initierieren
  a3_active = false;
  a4_active = true;
  a5_active = false;
  a6_active = false;
  a7_active = false;
  a8_active = false;


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
  if(m_triangle!=NULL)
    delete m_triangle;
  if(m_tricube!=NULL)
    delete m_tricube;
  if(m_polyline1!=NULL)
    delete m_polyline1;
  if(m_polyline2!=NULL)
    delete m_polyline2;
  if(m_polyline3!=NULL)
    delete m_polyline3;
  if(m_polyline4!=NULL)
    delete m_polyline4;
  if(m_polyline5!=NULL)
    delete m_polyline5;
  if(m_polyline6!=NULL)
    delete m_polyline6;
  if(m_polyline7!=NULL)
    delete m_polyline7;
  if(m_polyline8!=NULL)
    delete m_polyline8;
  if(m_polyline9!=NULL)
    delete m_polyline9;
  if(m_polyline10!=NULL)
    delete m_polyline10;
  if(m_polyline11!=NULL)
    delete m_polyline11;
  if(m_polyline12!=NULL)
    delete m_polyline12;


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

      a3_Renderer_init();
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
      std::cout << "CgSCeneControl: " << *ev << std::endl;

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
          m_tricube->init(pos,norm,indx);
          m_renderer->init(m_tricube);
        }
      m_renderer->redraw();
    }

  // an der Stelle an der ein Event abgearbeitet ist wird es auch gelöscht.
  delete e;


}

// A3 Hilfsmethoden id:0-19
void CgSceneControl::a3_object_initiation()
{
  m_tricube = new CgTriCube(1);
  m_polyline1 = new CgPolyline(2,m_tricube->getTriangleGravities()[0],m_tricube->getVertexNormals()[0]);
  m_polyline2 = new CgPolyline(3,m_tricube->getTriangleGravities()[1],m_tricube->getVertexNormals()[1]);
  m_polyline3 = new CgPolyline(4,m_tricube->getTriangleGravities()[2],m_tricube->getVertexNormals()[2]);
  m_polyline4 = new CgPolyline(5,m_tricube->getTriangleGravities()[3],m_tricube->getVertexNormals()[3]);
  m_polyline5 = new CgPolyline(6,m_tricube->getTriangleGravities()[4],m_tricube->getVertexNormals()[4]);
  m_polyline6 = new CgPolyline(7,m_tricube->getTriangleGravities()[5],m_tricube->getVertexNormals()[5]);
  m_polyline7 = new CgPolyline(8,m_tricube->getTriangleGravities()[6],m_tricube->getVertexNormals()[6]);
  m_polyline8 = new CgPolyline(9,m_tricube->getTriangleGravities()[7],m_tricube->getVertexNormals()[7]);
  m_polyline9 = new CgPolyline(10,m_tricube->getTriangleGravities()[8],m_tricube->getVertexNormals()[8]);
  m_polyline10 = new CgPolyline(11,m_tricube->getTriangleGravities()[9],m_tricube->getVertexNormals()[9]);
  m_polyline11 = new CgPolyline(12,m_tricube->getTriangleGravities()[10],m_tricube->getVertexNormals()[10]);
  m_polyline12 = new CgPolyline(13,m_tricube->getTriangleGravities()[11],m_tricube->getVertexNormals()[11]);
}

void CgSceneControl::a3_Renderer_render()
{
  if(m_tricube!=NULL)
    m_renderer->render(m_tricube);
  if(m_polyline1!=NULL)
    m_renderer->render(m_polyline1);
  if(m_polyline2!=NULL)
    m_renderer->render(m_polyline2);
  if(m_polyline3!=NULL)
    m_renderer->render(m_polyline3);
  if(m_polyline4!=NULL)
    m_renderer->render(m_polyline4);
  if(m_polyline5!=NULL)
    m_renderer->render(m_polyline5);
  if(m_polyline6!=NULL)
    m_renderer->render(m_polyline6);
  if(m_polyline7!=NULL)
    m_renderer->render(m_polyline7);
  if(m_polyline8!=NULL)
    m_renderer->render(m_polyline8);
  if(m_polyline9!=NULL)
    m_renderer->render(m_polyline9);
  if(m_polyline10!=NULL)
    m_renderer->render(m_polyline10);
  if(m_polyline11!=NULL)
    m_renderer->render(m_polyline11);
  if(m_polyline12!=NULL)
    m_renderer->render(m_polyline12);
}

void CgSceneControl::a3_Renderer_init()
{
  if(m_tricube!=NULL)
    m_renderer->init(m_tricube);
  if(m_polyline1!=NULL)
    m_renderer->init(m_polyline1);
  if(m_polyline2!=NULL)
    m_renderer->init(m_polyline2);
  if(m_polyline3!=NULL)
    m_renderer->init(m_polyline3);
  if(m_polyline4!=NULL)
    m_renderer->init(m_polyline4);
  if(m_polyline5!=NULL)
    m_renderer->init(m_polyline5);
  if(m_polyline6!=NULL)
    m_renderer->init(m_polyline6);
  if(m_polyline7!=NULL)
    m_renderer->init(m_polyline7);
  if(m_polyline8!=NULL)
    m_renderer->init(m_polyline8);
  if(m_polyline9!=NULL)
    m_renderer->init(m_polyline9);
  if(m_polyline10!=NULL)
    m_renderer->init(m_polyline10);
  if(m_polyline11!=NULL)
    m_renderer->init(m_polyline11);
  if(m_polyline12!=NULL)
    m_renderer->init(m_polyline12);
}

void CgSceneControl::a3_Renderer_reset()
{
  m_color_a3 = glm::vec4(1.0,0.0,0.0,1.0);
  m_renderer->redraw();
}


// A4 Hilfsmethoden id:20-39
void CgSceneControl::a4_object_initiation()
{
  std::vector<glm::vec3> test;
  test.push_back(glm::vec3(0.5,-1.0,0.0));
  test.push_back(glm::vec3(-0.5,-0.5,0.0));
  test.push_back(glm::vec3(-0.5,0.0,0.0));
  test.push_back(glm::vec3(0.5,0.5,0.0));
  test.push_back(glm::vec3(-0.5,1.0,0.0));


  m_polyline = new CgPolyline(20,test);
}

void CgSceneControl::a4_Renderer_render()
{
  if(m_polyline!=NULL)
    m_renderer->render(m_polyline);
}

void CgSceneControl::a4_Renderer_init()
{
  if(m_polyline!=NULL)
    m_renderer->init(m_polyline);
}

void CgSceneControl::a4_Renderer_reset()
{

}


// A5 Hilfsmethoden id:40-59
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

}

// A6 Hilfsmethoden id:60-79
void CgSceneControl::a6_object_initiation()
{

}

void CgSceneControl::a6_Renderer_render()
{

}

void CgSceneControl::a6_Renderer_init()
{

}

void CgSceneControl::a6_Renderer_reset()
{

}

// A7 Hilfsmethoden id:80-99
void CgSceneControl::a7_object_initiation()
{

}

void CgSceneControl::a7_Renderer_render()
{

}

void CgSceneControl::a7_Renderer_init()
{

}

void CgSceneControl::a7_Renderer_reset()
{

}

// A8 Hilfsmethoden id:100-119
void CgSceneControl::a8_object_initiation()
{

}

void CgSceneControl::a8_Renderer_render()
{

}

void CgSceneControl::a8_Renderer_init()
{

}

void CgSceneControl::a8_Renderer_reset()
{

}
