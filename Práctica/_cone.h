#ifndef _CONE_H
#define _CONE_H

#include "revolution_object.h"
/**
  * @author Inés Nieto Sánchez
**/
class _cone: public revolution_object
{
public:

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _bag
* @param Size, radio del cono
* @param N, número de caras a generar
*/
    _cone(float Size=1.0, int N = 50);
};

#endif // _CONE_H
