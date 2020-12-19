#ifndef _BAG_H
#define _BAG_H

#include "_cube.h"
class _bag
{
public:
    _bag();
    _cube Cube;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _BAG_H
