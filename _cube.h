#ifndef _CUBE_H
#define _CUBE_H

#include "object3d.h"
/**
  * @author Inés Nieto Sánchez
**/
class _cube:public _object3D
{
public:

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _cube
* @param Size, tamaño del cubo
*/
    _cube(float Size=1.0);
};

#endif // _CUBE_H
