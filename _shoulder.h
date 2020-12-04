#ifndef _SHOULDER_H
#define _SHOULDER_H

#include "_cylinder.h"

class _shoulder
{
public:
    _shoulder();
    _cylinder Cylinder;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();

};

#endif // _SHOULDER_H
