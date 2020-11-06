#ifndef _ARM_H
#define _ARM_H

#include "_cylinder.h"
class _arm
{
public:
    _arm();
    _cylinder Cylinder;

    void draw_line();
    void draw_point();
};

#endif // _ARM_H
