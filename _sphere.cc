#include "_sphere.h"

_sphere::_sphere(float Size, int N )
{
    int numero_puntos = 20;

    Vertices.resize(numero_puntos);
    for(int i=0; i < numero_puntos; i++)
        Vertices[i] = _vertex3f(Size/2*sin((PI/numero_puntos)*i),Size/2*cos((PI/numero_puntos)*i),0);

    crearRevolutionObject(N);
}
