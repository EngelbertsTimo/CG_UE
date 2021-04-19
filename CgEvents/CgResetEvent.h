#ifndef CGRESETEVENT_H
#define CGRESETEVENT_H

#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgResetEvent: public CgBaseEvent
{
public:
  CgResetEvent();
  CgResetEvent(Cg::EventType type,int aufgabe);

  //inherited
  Cg::EventType getType();
  CgBaseEvent* clone();

  int getAufgabe(){return m_aufgabe;}


private:
    Cg::EventType m_type;
    int m_aufgabe;
};
#endif // CGRESETEVENT_H
