#ifndef _UPPER_BODY_H
#define _UPPER_BODY_H

#include "_head_glass.h"
#include "_torso.h"
class _upper_body
{
public:
    _upper_body();
    _head_glass Head;
    _torso Torso;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
};

#endif // _UPPER_BODY_H
