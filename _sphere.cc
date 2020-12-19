#include "_sphere.h"

_sphere::_sphere(float Size, int N )
{
    int numero_puntos = 40;
    int indice = 0;

    Vertices.resize(numero_puntos);
    for(int i=numero_puntos-1; i >= 1; i--,indice++){
        Vertices[indice] = _vertex3f(Size/2*sin((PI/numero_puntos)*i),Size/2*cos((PI/numero_puntos)*i),0);
    }

    Vertices[Vertices.size()-2] = _vertex3f(0,Size/2,0);
    Vertices[Vertices.size()-1] = _vertex3f(0,-Size/2,0);

    int profile_points = Vertices.size();

//     crearRevolutionObject(N);

    crearRevolutionObjectNoOptimizado(N);
    Texture = calculateTextureCoordinate(N,profile_points);

    calculateNormalTriangles();
    calculateNormalVertices();
}
