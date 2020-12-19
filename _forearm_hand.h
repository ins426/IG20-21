#ifndef _FOREARM_HAND_H
#define _FOREARM_HAND_H

#include "_half_hand.h"
#include "_forearm.h"
class _forearm_hand
{
public:
    _forearm_hand();
    _half_hand HalfHand;
    _forearm Forearm;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();

    float positionHand = 0;
    float speedHand = 0.01;

    void increase_hands();
    void decrease_hands();
    void increaseSpeed_hands();
    void decreaseSpeed_hands();

};

#endif // _FOREARM_HAND_H
