#ifndef _LOWER_TORSO_H
#define _LOWER_TORSO_H

#include "_semisphere.h"
/**
  * @author Inés Nieto Sánchez
**/
class _lower_torso
{
public:
    _semisphere Semisphere;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _lower_torso
*/
    _lower_torso();

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

#endif // _LOWER_TORSO_H
