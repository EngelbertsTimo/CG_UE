#ifndef CGROTATIONEVENT_H
#define CGROTATIONEVENT_H

#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>


class CgRotationEvent: public CgBaseEvent
{
public:
  CgRotationEvent();
   CgRotationEvent(Cg::EventType type, int aufgabe, int rotationType, int segemente);
  //inherited
  Cg::EventType getType();
  CgBaseEvent* clone();

  int getAufgabe(){return m_aufgabe;}
  int getSegmente(){return m_segmente;}
  int getRotationType(){return m_rotationType;}

private:
  Cg::EventType m_type;
  int m_aufgabe;
  int m_segmente;
   int m_rotationType;
};

#endif // CGROTATIONEVENT_H



