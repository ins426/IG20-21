#ifndef _FOREARM_H
#define _FOREARM_H

#include "_cylinder.h"
class _forearm
{
public:
    _forearm();
    _cylinder Cylinder;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
};

#endif // _FOREARM_H
