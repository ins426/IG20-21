#ifndef _TWO_ARMS_H
#define _TWO_ARMS_H

#include "_whole_arm.h"
/**
  * @author Inés Nieto Sánchez
**/
class _two_arms
{
public:
    _whole_arm Arm;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _two_arms
*/
    _two_arms();

/***********************************************************************/
/**
* @brief Funciones para los distintos modos de dibujado
*/
    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _TWO_ARMS_H
