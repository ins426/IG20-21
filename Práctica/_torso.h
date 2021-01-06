#ifndef _BODY_H
#define _BODY_H

#include "_upper_torso.h"
#include "_lower_torso.h"
/**
  * @author Inés Nieto Sánchez
**/
class _torso
{
public:
    _upper_torso Upper_torso;
    _lower_torso Lower_torso;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _body_legs
*/
    _torso();

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

#endif // _BODY_H
