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
};

#endif // _GLASS_H