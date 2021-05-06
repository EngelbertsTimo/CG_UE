#ifndef CGRENDEREXTERNOBJECTEVENT_H
#define CGRENDEREXTERNOBJECTEVENT_H
#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgRenderExternObjectEvent :public CgBaseEvent
{
public:
  CgRenderExternObjectEvent(Cg::EventType type, int aufgabe, std::string objectName);
  CgRenderExternObjectEvent();
  int getAufagbenNummer(){return m_aufgabe;};
  std::string getObjectName(){return m_objectName;};
  //inherited
     Cg::EventType getType();
     CgBaseEvent* clone();

   private:
     Cg::EventType m_type;
   int m_aufgabe;
   std::string m_objectName;
};

#endif // CGRENDEREXTERNOBJECTEVENT_H


