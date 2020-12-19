#ifndef _TWO_ARMS_H
#define _TWO_ARMS_H

#include "_whole_arm.h"
class _two_arms
{
public:
    _two_arms();
    _whole_arm Arm;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _TWO_ARMS_H
