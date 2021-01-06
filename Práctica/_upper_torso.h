#ifndef _UPPER_TORSO_H
#define _UPPER_TORSO_H

#include "_cylinder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _upper_torso
{
public:
    _cylinder Cylinder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _upper_body
*/
    _upper_torso();

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

#endif // UPPER_TORSO_H
