#ifndef _BODY_LEGS_H
#define _BODY_LEGS_H

#include "_upper_body.h"
#include "_leg_wheel.h"

/**
  * @author Inés Nieto Sánchez
**/
class _body_legs
{
public:
    _upper_body Body;
    _leg_wheel Leg;

    float angleBody = 0;
    float speedBody = 1;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _body_legs
*/
    _body_legs();

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

/***********************************************************************/
/**
* @brief Incrementa el ángulo de rotación del cuerpo del robot
*/
    void increase_body();

/***********************************************************************/
/**
* @brief Decrementa el ángulo de rotación del cuerpo del robot
*/
    void decrease_body();

/***********************************************************************/
/**
* @brief Aumenta el incremento aplicado (speedBody) sobre angleBody
*/
    void increaseSpeed_body();
/***********************************************************************/
/**
* @brief Reduce el incremento aplicado (speedBody) sobre angleBody
*/
    void decreaseSpeed_body();

};

#endif // _BODY_LEGS_H
