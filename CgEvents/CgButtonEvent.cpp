#include "CgButtonEvent.h"

CgButtonEvent::CgButtonEvent(Cg::EventType type)
{
  m_type=type;
}

CgButtonEvent::CgButtonEvent()
{

}
CgBaseEvent* CgButtonEvent::clone(){
    return new CgButtonEvent(m_type);
}

Cg::EventType CgButtonEvent::getType(){
    return m_type;
}


