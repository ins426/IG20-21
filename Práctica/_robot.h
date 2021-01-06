#ifndef _ROBOT_H
#define _ROBOT_H

#include "_whole_body.h"
#include "_bag.h"
/**
  * @author Inés Nieto Sánchez
**/
class _robot
{
public:
    _whole_body Body;
    _bag Bag;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _robot
*/
    _robot();

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

#endif // HIERARCHICAL_MODEL_H
