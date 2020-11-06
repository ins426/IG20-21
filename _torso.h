#ifndef _BODY_H
#define _BODY_H

#include "_semisphere.h"
class _torso
{
public:
    _torso();
    _semisphere Semisphere;

    void draw_line();
    void draw_point();
};

#endif // _BODY_H
