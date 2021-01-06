#ifndef _ELBOW_H
#define _ELBOW_H

#include "_sphere.h"
/**
  * @author Inés Nieto Sánchez
**/
class _elbow
{
public:
    _sphere Sphere;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _elbow
*/
    _elbow();

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

#endif // _ELBOW_H
