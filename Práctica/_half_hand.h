#ifndef _HALF_HAND_H
#define _HALF_HAND_H

#include "_cube.h"
/**
  * @author Inés Nieto Sánchez
**/
class _half_hand
{
public:
    _cube Cube;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _half_hand
*/
    _half_hand();

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

#endif // _HAND_H
