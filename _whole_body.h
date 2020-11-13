#ifndef _WHOLE_BODY_H
#define _WHOLE_BODY_H

#include "_arm_hand.h"
#include "_body_legs.h"
class _whole_body
{
public:
    _whole_body();
    _arm_hand Arm;
    _body_legs Body_legs;

    void draw_line();
    void draw_point();

    void increase_arms();
    void decrease_arms();
    void increaseSpeed_arm();
    void decreaseSpeed_arm();

    float angleArm = 0;
    float speedArm = 1;
};

#endif // _WHOLE_BODY_H
