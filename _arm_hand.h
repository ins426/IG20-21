#ifndef _ARM_HAND_H
#define _ARM_HAND_H

#include "_whole_arm.h"
#include "_hand.h"
class _arm_hand
{
public:
    _arm_hand();
    _whole_arm Arm;
    _hand Hand;

    void draw_point();
    void draw_line();

    float positionHand = 0;
    float speedHand = 0.01;

    void increase_hands();
    void decrease_hands();
    void increaseSpeed_hands();
    void decreaseSpeed_hands();

};

#endif // _ARM_HAND_H
