#include "CgSceneControl.h"
#include "CgBase/CgEnums.h"
#include "CgEvents/CgMouseEvent.h"
#include "CgEvents/CgKeyEvent.h"
#include "CgEvents/CgWindowResizeEvent.h"
#include "CgEvents/CgLoadObjFileEvent.h"
#include "CgEvents/CgTrackballEvent.h"
#include "CgEvents/CgColorChangeEvent.h"
#include "CgEvents/CgButtonEvent.h"
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

  // Frabe ?
  m_color = glm::vec4(0.0,0.0,1.0,1.0);
  //  glm::mat4 mycolor = glm::vec4(0.0,1.0,0.0,1.0);


  m_triangle= new CgExampleTriangle(21);
  m_tricube = new CgTriCube();
  m_polyline1 = new CgPolyline(1,m_tricube->getTriangleGravities()[0],m_tricube->getVertexNormals()[0]);
  m_polyline2 = new CgPolyline(2,m_tricube->getTriangleGravities()[1],m_tricube->getVertexNormals()[1]);
  m_polyline3 = new CgPolyline(3,m_tricube->getTriangleGravities()[2],m_tricube->getVertexNormals()[2]);
  m_polyline4 = new CgPolyline(4,m_tricube->getTriangleGravities()[3],m_tricube->getVertexNormals()[3]);
  m_polyline5 = new CgPolyline(5,m_tricube->getTriangleGravities()[4],m_tricube->getVertexNormals()[4]);
  m_polyline6 = new CgPolyline(6,m_tricube->getTriangleGravities()[5],m_tricube->getVertexNormals()[5]);
  m_polyline7 = new CgPolyline(7,m_tricube->getTriangleGravities()[6],m_tricube->getVertexNormals()[6]);
  m_polyline8 = new CgPolyline(8,m_tricube->getTriangleGravities()[7],m_tricube->getVertexNormals()[7]);
  m_polyline9 = new CgPolyline(9,m_tricube->getTriangleGravities()[8],m_tricube->getVertexNormals()[8]);
  m_polyline10 = new CgPolyline(10,m_tricube->getTriangleGravities()[9],m_tricube->getVertexNormals()[9]);
  m_polyline11 = new CgPolyline(11,m_tricube->getTriangleGravities()[10],m_tricube->getVertexNormals()[10]);
  m_polyline12 = new CgPolyline(12,m_tricube->getTriangleGravities()[11],m_tricube->getVertexNormals()[11]);
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
  if (mode==1){
      if(m_triangle!=NULL)
        m_renderer->init(m_triangle);
    } else if(mode==2){
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
}


void CgSceneControl::renderObjects()
{

  // Materialeigenschaften setzen
  // sollte ja eigentlich pro Objekt unterschiedlich sein können, naja bekommen sie schon hin....

  std::cout << "CgSCeneControl: " <<"; render"<<std::endl;

  // m_renderer->setUniformValue("mycolor",glm::vec4(0.0,0.0,1.0,1.0));
  m_renderer->setUniformValue("mycolor",m_color);


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

  if(mode==1){
      if(m_triangle!=NULL)
        m_renderer->render(m_triangle);
    } else if(mode==2){
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
}



void CgSceneControl::handleEvent(CgBaseEvent* e)
{
  // die Enums sind so gebaut, dass man alle Arten von MausEvents über CgEvent::CgMouseEvent abprüfen kann,
  // siehe dazu die CgEvent enums im CgEnums.h

  if(e->getType() & Cg::ButtonEvent)
    {
      CgButtonEvent* ev =(CgButtonEvent*)e;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; mode chaneged"  <<std::endl;
      if (mode==1)
        mode =2;
      else
        mode=1;


      if (mode==1){
          if(m_triangle!=NULL)
            m_renderer->init(m_triangle);
        } else if(mode==2){
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
      m_renderer->redraw();
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

      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Modifier: red: " << ev->getRed() <<"; green: " << ev->getGreen()<<"; blue: " << ev->getBlue() <<std::endl;
      std::cout << "CgSCeneControl: " << "Eventtype: " <<ev->getType()<<"; Ergebnis: red: " << redPart <<"; green: " << greenPart<<"; blue: " << bluePart <<std::endl;

      m_color = glm::vec4(redPart,greenPart,bluePart,1.0);


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
