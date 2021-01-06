#include "_sphere.h"

_sphere::_sphere(float Size, int N, int n_points )
{
    int indice = 0;
    vector<_vertex3f> generatrix_curve;

    generatrix_curve.resize(n_points);
    for(int i=n_points-1; i >= 1; i--,indice++){
        generatrix_curve[indice] = _vertex3f(Size/2*sin((PI/n_points)*i),Size/2*cos((PI/n_points)*i),0);
    }

    generatrix_curve[generatrix_curve.size()-2] = _vertex3f(0,Size/2,0);
    generatrix_curve[generatrix_curve.size()-1] = _vertex3f(0,-Size/2,0);

    int profile_points = generatrix_curve.size();

    crearRevolutionObject(N,generatrix_curve);

   //crearRevolutionObjectNoOptimizado(N, generatrix_curve);
   //Texture = calculateTextureCoordinate(N,profile_points);

    calculateNormalTriangles();
    calculateNormalVertices();
}
