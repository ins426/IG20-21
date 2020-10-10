#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "revolution_object.h"

class _cylinder:public revolution_object
{
public:
    _cylinder(float Size=1.0, int N = 50);
};

#endif // _CYLINDER_H
