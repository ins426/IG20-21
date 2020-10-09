#include "_cone.h"

_cone::_cone(float Size, int N)
{
    Vertices.resize(1);

    Vertices[0] = _vertex3f(Size/2,0,0);

    createPoints(N,1);

    Vertices.resize(Vertices.size()+2);
    Vertices[Vertices.size()-2] = _vertex3f(0,Size/2,0);
    Vertices[Vertices.size()-1]= _vertex3f(0,0,0);

}
