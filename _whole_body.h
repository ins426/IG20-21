#ifndef _WHOLE_BODY_H
#define _WHOLE_BODY_H

#include "_two_arms.h"
#include "_body_legs.h"
/**
  * @author Inés Nieto Sánchez
**/
class _whole_body
{
public:
    _two_arms Arms;
    _body_legs Body_legs;

    float angleArms = 0;
    float speedArms = 1;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _whole_body
*/
    _whole_body();

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

/***********************************************************************/
/**
* @brief Incrementa el ángulo de rotación de los brazos del robot
*/
    void increase_arms();

/***********************************************************************/
/**
* @brief Decrementa el ángulo de rotación de los brazos del robot
*/
    void decrease_arms();

/***********************************************************************/
/**
* @brief Aumenta el incremento aplicado (speedArms) sobre angleArms
*/
    void increaseSpeed_arm();

/***********************************************************************/
/**
* @brief Reduce el incremento aplicado (speedArms) sobre angleArms
*/
    void decreaseSpeed_arm();

};

#endif // _WHOLE_BODY_H
