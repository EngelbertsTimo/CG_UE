#ifndef CGAUFGABENSTATUSEVENT_H
#define CGAUFGABENSTATUSEVENT_H
#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgAufgabenStatusEvent: public CgBaseEvent
{
public:
  CgAufgabenStatusEvent();
  CgAufgabenStatusEvent(Cg::EventType type, int aufgabe, bool status);

  int getAufagbenNummer(){return m_aufgabe;};
 bool getAufgabenStatus(){return m_status;};

  //inherited
  Cg::EventType getType();
  CgBaseEvent* clone();

private:
  Cg::EventType m_type;
  int m_aufgabe;
  bool m_status;
};

#endif // CGAUFGABENSTATUSEVENT_H


