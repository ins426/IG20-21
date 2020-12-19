#ifndef _HALF_HAND_H
#define _HALF_HAND_H

#include "_cube.h"
class _half_hand
{
public:
    _half_hand();
    _cube Cube;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();


};

#endif // _HAND_H
