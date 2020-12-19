#ifndef _ELBOW_H
#define _ELBOW_H

#include "_sphere.h"
class _elbow
{
public:
    _elbow();
    _sphere Sphere;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _ELBOW_H
