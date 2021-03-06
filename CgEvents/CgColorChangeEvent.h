#ifndef CGCOLORCHANGEEVENT_H
#define CGCOLORCHANGEEVENT_H

#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgColorChangeEvent: public CgBaseEvent
        //class CgColorChangeEvent
{
public:
    CgColorChangeEvent();

    CgColorChangeEvent(Cg::EventType type,int aufgabe, int16_t red,int16_t green,int16_t blue );

    //inherited
    Cg::EventType getType();
    CgBaseEvent* clone();

    int getRed(){return m_red;}
    int getGreen(){return m_green;}
    int getBlue(){return m_blue;}
    int getAufgabe(){return m_aufgabe;}

private:
    Cg::EventType m_type;
    int m_aufgabe;
    int m_red;
    int m_green;
    int m_blue;

};

#endif // CGCOLORCHANGEEVENT_H
