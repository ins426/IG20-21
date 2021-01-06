#include "_cylinder.h"

_cylinder::_cylinder(int N, float H, float R)
{
    vector<_vertex3f> generatrix_curve;
    generatrix_curve.resize(4);

    generatrix_curve[0] = _vertex3f(R,0,0);
    generatrix_curve[1] = _vertex3f(R,H,0);
    generatrix_curve[2] = _vertex3f(0,H,0);
    generatrix_curve[3]= _vertex3f(0,0,0);

    int profile_points = generatrix_curve.size();

    crearRevolutionObject(N,generatrix_curve);
    //crearRevolutionObjectNoOptimizado(N,generatrix_curve);
    //Texture = calculateTextureCoordinate(N,profile_points);

    calculateNormalTriangles();
    calculateNormalVertices();
}
