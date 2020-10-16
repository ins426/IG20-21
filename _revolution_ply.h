#ifndef _REVOLUTION_PLY_H
#define _REVOLUTION_PLY_H

#include "revolution_object.h"
#include "_ply.h"

class _revolution_ply: public revolution_object, _ply
{
public:
    _revolution_ply();
    void rota_ply(const string &File_name);
};

#endif // _REVOLUTION_PLY_H
