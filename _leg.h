#ifndef _LEG_H
#define _LEG_H

#include "_cylinder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _leg
{
public:
    _cylinder Cylinder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _leg
*/
    _leg();

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

#endif // _LEG_H
