#ifndef _HAND_H
#define _HAND_H

#include "_cube.h"
class _hand
{
public:
    _hand();
    _cube Cube;

    void draw_point();
    void draw_line();
};

#endif // _HAND_H
