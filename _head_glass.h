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
};

#endif // _HEAD_GLASS_H
