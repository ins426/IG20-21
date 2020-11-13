#ifndef _WHOLE_ARM_H
#define _WHOLE_ARM_H

#include "_arm.h"
#include "_elbow.h"
#include "_forearm.h"
class _whole_arm
{
public:
    _whole_arm();
    _arm Arm;
    _elbow Elbow;
    _forearm Forearm;

    void draw_line();
    void draw_point();

};

#endif // _WHOLE_ARM_H
