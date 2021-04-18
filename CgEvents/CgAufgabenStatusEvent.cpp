#include "CgAufgabenStatusEvent.h"

CgAufgabenStatusEvent::CgAufgabenStatusEvent()
{

}

CgAufgabenStatusEvent::CgAufgabenStatusEvent(Cg::EventType type, int aufgabe,bool status)
{
   std::cout << "CgAufgabenStatusEvent: " << "Aufgabe "<< aufgabe<<" Status changed to "<< status << std::endl;
   m_type=type;
   m_aufgabe=aufgabe;
   m_status=status;

}



CgBaseEvent* CgAufgabenStatusEvent::clone(){
    return new CgAufgabenStatusEvent(m_type,m_aufgabe,m_status);
}

Cg::EventType CgAufgabenStatusEvent::getType(){
    return m_type;
}

