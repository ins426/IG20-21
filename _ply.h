#ifndef _PLY_H
#define _PLY_H

#include "object3d.h"
#include "file_ply_stl.h"
class _ply:public _object3D
{
public:
    _ply();
    bool readPly();
};

#endif // _PLY_H
