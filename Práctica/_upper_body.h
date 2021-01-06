#ifndef _UPPER_BODY_H
#define _UPPER_BODY_H

#include "_head_glass.h"
#include "_torso.h"
/**
  * @author Inés Nieto Sánchez
**/
class _upper_body
{
public:
    _head_glass Head;
    _torso Torso;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _upper_body
*/
    _upper_body();

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

#endif // _UPPER_BODY_H
