#ifndef _WHEEL_H
#define _WHEEL_H

#include "_cylinder.h"
class _wheel
{
public:
    _wheel();
    _cylinder Cylinder;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _WHEEL_H
