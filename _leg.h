#ifndef _LEG_H
#define _LEG_H

#include "_cylinder.h"
class _leg
{
public:
    _leg();
    _cylinder Cylinder;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _LEG_H
