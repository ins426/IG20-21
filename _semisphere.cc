#include "_semisphere.h"

_semisphere::_semisphere(float Size, int N)
{
    int numero_puntos = 180;

    Vertices.resize(numero_puntos);
    for(int i=0; i < numero_puntos; i++)
        Vertices[i] = _vertex3f(Size/2*sin(((PI/2)/numero_puntos)*i),Size/2*cos(((PI/2)/numero_puntos)*i),0);

    crearRevolutionObject(N);
}
