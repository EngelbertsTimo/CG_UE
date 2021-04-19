#include "CgResetEvent.h"

CgResetEvent::CgResetEvent(Cg::EventType type,int aufgabe)
{
  m_type=type;
  m_aufgabe=aufgabe;
}


CgBaseEvent* CgResetEvent::clone(){
    return new CgResetEvent(m_type,m_aufgabe);
}

Cg::EventType CgResetEvent::getType(){
    return m_type;
}

