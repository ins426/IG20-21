#ifndef _FOREARM_HAND_H
#define _FOREARM_HAND_H

#include "_half_hand.h"
#include "_forearm.h"
/**
  * @author Inés Nieto Sánchez
**/
class _forearm_hand
{
public:
    _half_hand HalfHand;
    _forearm Forearm;

    float positionHand = 0;
    float speedHand = 0.01;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _forearm_hand
*/
    _forearm_hand();

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
* @brief Incrementa la posición de la mitad de una mano
*/
    void increase_hands();

/***********************************************************************/
/**
* @brief Decrementa la posición de la mitad de una mano
*/
    void decrease_hands();

/***********************************************************************/
/**
* @brief Aumenta el incremento aplicado (speedHand) sobre positionHand
*/
    void increaseSpeed_hands();

/***********************************************************************/
/**
* @brief Reduce el incremento aplicado (speedHand) sobre positionHand
*/
    void decreaseSpeed_hands();

};

#endif // _FOREARM_HAND_H
