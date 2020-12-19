#ifndef _HEAD_H
#define _HEAD_H

#include "_semisphere.h"
class _head
{
public:
    _head();
    _semisphere Semisphere;

     void draw_line();
     void draw_point();
     void draw_chess();
     void draw_fill();
     void draw_flat();
     void draw_smooth();
};

#endif // _HEAD_H
