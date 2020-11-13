#include "_cone.h"

_cone::_cone(float Size, int N)
{
    Vertices.resize(3);

    Vertices[0] = _vertex3f(Size/2,0,0);
    Vertices[1] = _vertex3f(0,Size/2,0);
    Vertices[2]= _vertex3f(0,0,0);

    crearRevolutionObject(10);

}
