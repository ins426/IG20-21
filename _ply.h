#ifndef _PLY_H
#define _PLY_H

#include "object3d.h"
#include "file_ply_stl.h"
class _ply: virtual public _object3D
{
public:
    _ply(string File_name= "/home/ines/Documentos/GitHub/IG20-21/ply_models/beethoven.ply");
    bool readPly(const string &File_name);
};

#endif // _PLY_H
