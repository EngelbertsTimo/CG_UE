#include "CgRenderExternObjectEvent.h"

CgRenderExternObjectEvent::CgRenderExternObjectEvent(){

}

CgRenderExternObjectEvent::CgRenderExternObjectEvent(Cg::EventType type, int aufgabe, std::string objectName)
{
  std::cout << "CgRenderExternObjectEvent: " << "Aufgabe "<< aufgabe<< "; render Object: "<< objectName<<std::endl;
  m_type=type;
  m_aufgabe=aufgabe;
  m_objectName=objectName;
}

CgBaseEvent* CgRenderExternObjectEvent::clone(){
    return new CgRenderExternObjectEvent(m_type,m_aufgabe,m_objectName);
}

Cg::EventType CgRenderExternObjectEvent::getType(){
    return m_type;
}
