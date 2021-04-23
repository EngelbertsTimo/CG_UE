#include "CgShowNormalsEvent.h"

CgShowNormalsEvent::CgShowNormalsEvent()
{

}

CgShowNormalsEvent::CgShowNormalsEvent(Cg::EventType type, int aufgabe,bool status, int normalType)
{
  std::cout << "CgShowNormalsEvent: " << "Aufgabe "<< aufgabe<<"Normal Status changed to "<< status << "| normal Type = "<<normalType<< std::endl;
  m_type=type;
  m_aufgabe=aufgabe;
  m_status=status;
  m_normalType=normalType;
}

CgBaseEvent* CgShowNormalsEvent::clone(){
    return new CgShowNormalsEvent(m_type,m_aufgabe,m_status,m_normalType);
}

Cg::EventType CgShowNormalsEvent::getType(){
    return m_type;
}

