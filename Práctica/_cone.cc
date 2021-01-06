#include "_cone.h"

_cone::_cone(float Size, int N)
{
    vector<_vertex3f> generatrix_curve;
    generatrix_curve.resize(3);

    generatrix_curve[0] = _vertex3f(Size/2,0,0);
    generatrix_curve[1] = _vertex3f(0,Size/2,0);
    generatrix_curve[2]= _vertex3f(0,0,0);

    crearRevolutionObject(N,generatrix_curve);
    calculateNormalTriangles();
    calculateNormalVertices();

}
