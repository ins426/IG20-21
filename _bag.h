#ifndef _BAG_H
#define _BAG_H

#include "_cube.h"
/**
  * @author Inés Nieto Sánchez
**/
class _bag
{
public:
    _cube Cube;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _bag
*/
    _bag();

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

#endif // _BAG_H
