#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "revolution_object.h"

class _cylinder:public revolution_object
{
public:
    _cylinder(int N = 5, float H=1, float R=0.5);
    vector<_vertex2f> NormalTriangles;

    void calculateNormalTriangles();
};

#endif // _CYLINDER_H
