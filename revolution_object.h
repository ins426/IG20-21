#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

#include "object3d.h"

class revolution_object:public _object3D
{
public:
    revolution_object();
    void createRevolutionObject(const float R, const int N, vector<_vertex3f> profile_points);
    void createPoints(const float R, const int N, vector<_vertex3f> profile_points);

};

const float DOS_PI = 2*3.14159265358979;

#endif // REVOLUTION_OBJECT_H
