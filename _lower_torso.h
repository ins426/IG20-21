#ifndef _LOWER_TORSO_H
#define _LOWER_TORSO_H

#include "_semisphere.h"
class _lower_torso
{
public:
    _lower_torso();
    _semisphere Semisphere;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _LOWER_TORSO_H
