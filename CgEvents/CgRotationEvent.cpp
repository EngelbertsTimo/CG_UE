#include "CgRotationEvent.h"

CgRotationEvent::CgRotationEvent()
{

}

CgRotationEvent::CgRotationEvent(Cg::EventType type,int aufgabe,int segemente)
{
  m_type=type;
  m_aufgabe=aufgabe;
  m_segmente = segemente;

}



CgBaseEvent* CgRotationEvent::clone(){
    return new CgRotationEvent(m_type,m_aufgabe,m_segmente);
}

Cg::EventType CgRotationEvent::getType(){
    return m_type;
}
