#include "_cylinder.h"

_cylinder::_cylinder()
{
    vector<_vertex3f> v;
    v.resize(2);
    v[0].x = 10;
    v[0].y = 0;
    v[0].z = 0;

    v[1].x = 10;
    v[1].y = 10;
    v[1].z = 0;
    createPoints(10,10,v);
}
