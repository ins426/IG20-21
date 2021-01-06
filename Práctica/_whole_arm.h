#ifndef _WHOLE_ARM_H
#define _WHOLE_ARM_H

#include "_forearm_elbow.h"
#include "_shoulder.h"
/**
  * @author Inés Nieto Sánchez
**/
class _whole_arm
{
public:
    _forearm_elbow Forearm_elbow;
    _shoulder Shoulder;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _whole_arm
*/
    _whole_arm();

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

#endif // _WHOLE_ARM_H
