#ifndef _LEG_WHEEL_H
#define _LEG_WHEEL_H

#include "_wheel.h"
#include "_leg.h"
class _leg_wheel
{
public:
    _leg_wheel();
    _leg Leg;
    _wheel Wheel;

    void draw_point();
    void draw_line();
};

#endif // _LEG_WHEEL_H
