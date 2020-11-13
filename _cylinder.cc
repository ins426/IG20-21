#include "_cylinder.h"

_cylinder::_cylinder(int N, float H, float R)
{
    Vertices.resize(4);

    Vertices[0] = _vertex3f(R,H,0);
    Vertices[1] = _vertex3f(R,0,0);
    Vertices[2] = _vertex3f(0,H,0);
    Vertices[3]= _vertex3f(0,0,0);

    crearRevolutionObject(N);


}
