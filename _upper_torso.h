#ifndef _UPPER_TORSO_H
#define _UPPER_TORSO_H

#include "_cylinder.h"
class _upper_torso
{
public:
    _upper_torso();

    _cylinder Cylinder;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
};

#endif // UPPER_TORSO_H
