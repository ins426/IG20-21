#ifndef _ARM_HAND_H
#define _ARM_HAND_H

#include "_arm.h"
#include "_hand.h"
class _arm_hand
{
public:
    _arm_hand();
    _arm Arm;
    _hand Hand;

    void draw_point();
    void draw_line();
};

#endif // _ARM_HAND_H
