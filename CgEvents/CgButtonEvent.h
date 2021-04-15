#ifndef CGBUTTONEVENT_H
#define CGBUTTONEVENT_H

#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"

#include <iostream>
#include <string>

class CgButtonEvent: public CgBaseEvent
{
public:
  CgButtonEvent();
   CgButtonEvent(Cg::EventType type);
   //inherited
   Cg::EventType getType();
   CgBaseEvent* clone();

private:
    Cg::EventType m_type;
};

#endif // CGBUTTONEVENT_H

