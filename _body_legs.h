#ifndef _BODY_LEGS_H
#define _BODY_LEGS_H

#include "_upper_body.h"
#include "_leg_wheel.h"
class _body_legs
{
public:
    _body_legs();
    _upper_body Body;
    _leg_wheel Leg;

    void draw_point();
    void draw_line();

    void increase_body();
    void decrease_body();
    void increaseSpeed_body();
    void decreaseSpeed_body();

    float angleBody = 0;
    float speedBody = 1;

};

#endif // _BODY_LEGS_H
