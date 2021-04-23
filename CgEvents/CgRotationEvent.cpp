#include "CgRotationEvent.h"

CgRotationEvent::CgRotationEvent()
{

}

CgRotationEvent::CgRotationEvent(Cg::EventType type,int aufgabe, int rotationType,int segemente)
{
  m_type=type;
  m_aufgabe=aufgabe;
  m_segmente = segemente;
  m_rotationType=rotationType;

}



CgBaseEvent* CgRotationEvent::clone(){
    return new CgRotationEvent(m_type,m_aufgabe,m_rotationType,m_segmente);
}

Cg::EventType CgRotationEvent::getType(){
    return m_type;
}
