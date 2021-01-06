#ifndef _SHOULDER_H
#define _SHOULDER_H

#include "_cylinder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _shoulder
{
public:
    _cylinder Cylinder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _shoulder
*/
    _shoulder();

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

#endif // _SHOULDER_H
