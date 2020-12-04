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
};

#endif // _ELBOW_H
