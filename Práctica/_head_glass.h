#ifndef _HEAD_GLASS_H
#define _HEAD_GLASS_H

#include "_head.h"
#include "_glass.h"
/**
  * @author Inés Nieto Sánchez
**/
class _head_glass
{
public:
    _head Head;
    _glass Glass;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _head_glass
*/
    _head_glass();

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

#endif // _HEAD_GLASS_H
