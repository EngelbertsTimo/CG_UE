#ifndef CGSHOWNORMALSEVENT_H
#define CGSHOWNORMALSEVENT_H
#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>


class CgShowNormalsEvent: public CgBaseEvent
{
public:
  CgShowNormalsEvent();
   CgShowNormalsEvent(Cg::EventType type, int aufgabe, bool status,int normalType);
   int getAufagbenNummer(){return m_aufgabe;};
   int getNormalType(){return m_normalType;};
  bool getNormalStatus(){return m_status;};

   //inherited
   Cg::EventType getType();
   CgBaseEvent* clone();

 private:
   Cg::EventType m_type;
   int m_aufgabe;
   int m_normalType;
   bool m_status;

};

#endif // CGSHOWNORMALSEVENT_H

