#ifndef CGLRAGLAETENEVENT_H
#define CGLRAGLAETENEVENT_H

#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgLRAglaetenEvent: public CgBaseEvent
{
public:
  CgLRAglaetenEvent();
  CgLRAglaetenEvent(Cg::EventType type,int aufgabe,int schritte, int iterationen);

  //inherited
  Cg::EventType getType();
  CgBaseEvent* clone();

  int getAufgabe(){return m_aufgabe;}
  int getSchritte(){return m_schritte;}
  int getIterationen(){return m_iterationen;}

private:
  Cg::EventType m_type;
  int m_aufgabe;
  int m_schritte;
  int m_iterationen;
};

#endif // CGLRAGLAETENEVENT_H




