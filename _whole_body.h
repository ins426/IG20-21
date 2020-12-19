#ifndef _WHOLE_BODY_H
#define _WHOLE_BODY_H

#include "_two_arms.h"
#include "_body_legs.h"
class _whole_body
{
public:
    _whole_body();
    _two_arms Arms;
    _body_legs Body_legs;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();

    void increase_arms();
    void decrease_arms();
    void increaseSpeed_arm();
    void decreaseSpeed_arm();

    float angleArms = 0;
    float speedArms = 1;
};

#endif // _WHOLE_BODY_H
