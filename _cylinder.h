#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "revolution_object.h"
/**
  * @author Inés Nieto Sánchez
**/
class _cylinder:public revolution_object
{
public:

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _cylinder
* @param N, número de caras a generar
* @param H, altura del cilindro
* @param R, radio del cilindro
*/
    _cylinder(int N = 50, float H=1, float R=0.5);

};

#endif // _CYLINDER_H
