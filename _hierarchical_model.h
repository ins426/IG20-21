#ifndef _HIERARCHICAL_MODEL_H
#define _HIERARCHICAL_MODEL_H

#include "_whole_body.h"
#include "_bag.h"
class _hierarchical_model
{
public:
    _hierarchical_model();
    _whole_body Body;
    _bag Bag;

    void draw_point();
    void draw_line();
};

#endif // HIERARCHICAL_MODEL_H
