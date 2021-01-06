#ifndef _SEMISPHERE_H
#define _SEMISPHERE_H

#include "revolution_object.h"
/**
  * @author Inés Nieto Sánchez
**/
class _semisphere: public revolution_object
{
public:

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _semisphere
* @param Size, radio de la semiesfera
* @param N, número de caras a generar
*/
    _semisphere(float Size=1.0, int N = 180);
};

#endif // _SEMISPHERE_H
