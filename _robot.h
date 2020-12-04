#ifndef _ROBOT_H
#define _ROBOT_H

#include "_whole_body.h"
#include "_bag.h"
class _robot
{
public:
    _robot();
    _whole_body Body;
    _bag Bag;

    void draw_point();
    void draw_line();
    void draw_chess();
    void draw_fill();

};

#endif // HIERARCHICAL_MODEL_H
