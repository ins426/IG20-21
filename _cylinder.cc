#include "_cylinder.h"

_cylinder::_cylinder(float Size, int N)
{
    Vertices.resize(2);

    Vertices[0] = _vertex3f(Size/2,0,0);
    Vertices[1] = _vertex3f(Size/2,Size/2,0);

    createPoints(N,2);

    Vertices.resize(Vertices.size()+2);
    Vertices[Vertices.size()-2] = _vertex3f(0,Size/2,0);
    Vertices[Vertices.size()-1]= _vertex3f(0,0,0);

}
