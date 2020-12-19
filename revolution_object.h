#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "object3d.h"

class revolution_object: virtual public _object3D
{
public:
    revolution_object();
    void crearRevolutionObject(const int N);
    void rotarPuntos(const int N, int num_rotar);
    void rotarPuntosRepetidos(const int N, int num_rotar);
    void crearCara(const int N, int num_rotar);
    void crearTapaSuperior(const int N, int num_rotar);
    void crearTapaInferior(int N,int num_rotar);

    void cambiarSentido();

    void crearRevolutionObjectNoOptimizado(const int N);
    void crearTapaSuperiorRepetida(const int N, int num_rotar);
    void crearCaraRepetida(const int N, int num_rotar);
    void crearTapaInferiorRepetida(const int N, int num_rotar);

    vector<_vertex2f> calculateTextureCoordinate(const int N,int profile_points);
    void calculateFaceTextureCoordinate(const int N, int profile_points,vector<_vertex2f> &Texture, vector<float> distances);
    void calculateTapaTextureCoordinate(int start,const int N, int profile_points,vector<_vertex2f> &Texture, vector<float> distances);
    void calculateVerticesDistance(vector<float>&distances, int N,int profile_points);
    float calculateDistance(_vertex3f v1, _vertex3f v2);

};

const float PI = M_PI;
const float DOS_PI = 2*PI;

#endif // REVOLUTION_OBJECT_H
