#ifndef RUEDA_H
#define RUEDA_H

#include "_cylinder.h"
class rueda
{
public:
    rueda();

    _cylinder Cylinder;

    //void _cylinder(unsigned int N=3, float Radius=0.5, float Height=1);

    void draw_point();
    void draw_line();
};

#endif // RUEDA_H
