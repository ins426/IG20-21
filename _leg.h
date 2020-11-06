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
};

#endif // _LEG_H
