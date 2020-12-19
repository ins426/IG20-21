#ifndef _GLASS_H
#define _GLASS_H

#include "_semisphere.h"
class _glass
{
public:
    _glass();
    _semisphere Semisphere;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _GLASS_H
