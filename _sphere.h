#ifndef _SPHERE_H
#define _SPHERE_H

#include "revolution_object.h"
/**
  * @author Inés Nieto Sánchez
**/
class _sphere: public revolution_object
{
public:

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _sphere
* @param Size, radio de la esfera
* @param N, número de caras a generar
* @param n_points, número de vértices del perfil a generar
*/
    _sphere(float Size=1.0, int N =40, int n_points = 40);
};

#endif // _SPHERE_H
