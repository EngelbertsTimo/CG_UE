#include "CgLRAglaetenEvent.h"

CgLRAglaetenEvent::CgLRAglaetenEvent(Cg::EventType type,int aufgabe,int schritte, int iterationen)
{
  m_type=type;
  m_aufgabe=aufgabe;
  m_schritte = schritte;
  m_iterationen = iterationen;
}



CgBaseEvent* CgLRAglaetenEvent::clone(){
    return new CgLRAglaetenEvent(m_type,m_aufgabe,m_schritte,m_iterationen);
}

Cg::EventType CgLRAglaetenEvent::getType(){
    return m_type;
}
