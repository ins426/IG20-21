#ifndef _LEG_WHEEL_H
#define _LEG_WHEEL_H

#include "_wheel.h"
#include "_leg.h"
/**
  * @author Inés Nieto Sánchez
**/
class _leg_wheel
{
public:
    _leg Leg;
    _wheel Wheel;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _leg_wheel
*/
    _leg_wheel();

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

#endif // _LEG_WHEEL_H
