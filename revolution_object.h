#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

#include "object3d.h"

class revolution_object:public _object3D
{
public:
    revolution_object();
    void crearRevolutionObject(const int N);
    void rotarPuntos(const int N, int num_rotar);
    void crearCara(const int N, int num_rotar);
    void crearTapaSuperior(const int N, int num_rotar);
    void crearTapaInferior(int N,int num_rotar);
    void cambiarSentido();

};

const float PI = 3.14159265358979;
const float DOS_PI = 2*PI;

#endif // REVOLUTION_OBJECT_H
