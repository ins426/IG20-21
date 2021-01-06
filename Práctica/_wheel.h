#ifndef _WHEEL_H
#define _WHEEL_H

#include "_cylinder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _wheel
{
public:
    _cylinder Cylinder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _wheel
*/
    _wheel();

/***********************************************************************/
/**
* @brief Funciones para los distintos modos de dibujado
*/
    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _WHEEL_H
