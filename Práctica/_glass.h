#ifndef _GLASS_H
#define _GLASS_H

#include "_semisphere.h"
/**
  * @author Inés Nieto Sánchez
**/
class _glass
{
public:
    _semisphere Semisphere;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _glass
*/
    _glass();

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

#endif // _GLASS_H
