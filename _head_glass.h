#ifndef _HEAD_GLASS_H
#define _HEAD_GLASS_H

#include "_head.h"
#include "_glass.h"
class _head_glass
{
public:
    _head_glass();
    _head Head;
    _glass Glass;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _HEAD_GLASS_H
