#ifndef _WHOLE_ARM_H
#define _WHOLE_ARM_H

#include "_forearm_elbow.h"
#include "_shoulder.h"
class _whole_arm
{
public:
    _whole_arm();
    _forearm_elbow Forearm_elbow;
    _shoulder Shoulder;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _WHOLE_ARM_H
