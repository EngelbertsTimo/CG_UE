#include "CgColorChangeEvent.h"



CgColorChangeEvent::CgColorChangeEvent(Cg::EventType type, std::int16_t red,std::int16_t green,std::int16_t blue)
{
    std::cout << "CgColorCHangeEvent: " << "red input Value  " <<red << std::endl;
    m_type=type;
    m_red = red;
    std::cout << "CgColorCHangeEvent: " << "red stored Value  " <<m_red << std::endl;
    m_green = green;
    m_blue = blue;
}

CgColorChangeEvent::CgColorChangeEvent()
{

}

CgBaseEvent* CgColorChangeEvent::clone(){
    return new CgColorChangeEvent(m_type,m_red,m_green,m_blue);
}

Cg::EventType CgColorChangeEvent::getType(){
    return m_type;
}

