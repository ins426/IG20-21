#ifndef _FOREARM_ELBOW_H
#define _FOREARM_ELBOW_H

#include "_forearm_hand.h"
#include "_elbow.h"
class _forearm_elbow
{
public:
    _forearm_elbow();
    _elbow Elbow;
    _forearm_hand Forearm_hand;

    void draw_line();
    void draw_point();
    void draw_chess();
    void draw_fill();
    void draw_flat();
    void draw_smooth();
};

#endif // _FOREARM_ELBOW_H
