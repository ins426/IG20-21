#ifndef _FOREARM_H
#define _FOREARM_H

#include "_cylinder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _forearm
{
public:
    _cylinder Cylinder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _forearm
*/
    _forearm();

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

#endif // _FOREARM_H
