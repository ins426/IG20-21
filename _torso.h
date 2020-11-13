#ifndef _BODY_H
#define _BODY_H

#include "_upper_torso.h"
#include "_lower_torso.h"
class _torso
{
public:
    _torso();
    _upper_torso Upper_torso;
    _lower_torso Lower_torso;

    void draw_line();
    void draw_point();
};

#endif // _BODY_H
