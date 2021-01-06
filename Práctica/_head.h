#ifndef _HEAD_H
#define _HEAD_H

#include "_semisphere.h"
/**
  * @author Inés Nieto Sánchez
**/
class _head
{
public:
    _semisphere Semisphere;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _head
*/
    _head();

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

#endif // _HEAD_H
