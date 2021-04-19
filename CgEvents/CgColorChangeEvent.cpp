#include "CgColorChangeEvent.h"



CgColorChangeEvent::CgColorChangeEvent(Cg::EventType type,int aufgabe, std::int16_t red,std::int16_t green,std::int16_t blue)
{

    m_type=type;
    m_aufgabe=aufgabe;
    m_red = red;   
    m_green = green;
    m_blue = blue;
}

CgColorChangeEvent::CgColorChangeEvent()
{

}

CgBaseEvent* CgColorChangeEvent::clone(){
    return new CgColorChangeEvent(m_type,m_aufgabe,m_red,m_green,m_blue);
}

Cg::EventType CgColorChangeEvent::getType(){
    return m_type;
}

